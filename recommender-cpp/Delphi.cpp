#include "Delphi.h"
#include"SimilarityMatrixRepository.h"

Delphi::Delphi(DataSet&dataSet, RecommendationType type)
{

	_type = type;
	SimilarityMatrixRepository* smRepo = new SimilarityMatrixRepository();
	_similarityMatrix = smRepo->load(type, dataSet);
	_dataset = &dataSet;

	_maxPredictedRating = new unordered_map<int, double>(dataSet.getUserCount() / 2);
	_similarUsers = new vector<SimilarUser>();
	_recommendations = new vector<PredictedItemRating>();
}


Delphi::~Delphi()
{
	delete _similarityMatrix;
	delete _maxPredictedRating;
	 delete _similarUsers;
	 delete _recommendations;
}
const double Delphi::DEFAULT_SIMILARITY_THRESHOLD = 0.5;
const double Delphi::MAX_RATING = 5;

vector<SimilarUser> Delphi::findSimilarUsers(const User& user, int topN)const{

	if (isUserBased()) {

		 findFriendsBasedOnUserSimilarity(user);

	}
	else {

		/**
		* TODO: 3.x: Create an algorithm that would allow you to find
		* similar users based on item similarities.
		*   What kind of results do you get?
		*   Is it space efficient?
		*   How about execution time?
		*/
	}
	return SimilarUser::getTopNFriends(*_similarUsers, topN);
}

void Delphi::findFriendsBasedOnUserSimilarity(const User& user)const {

	for (User& fr : *(_dataset->getUsers())) {

		if (user.getId() != fr.getId()) {

			double similarity =
				_similarityMatrix->getValue(user.getId(), fr.getId());
			SimilarUser s(fr, similarity);
			_similarUsers->push_back(s);
		}
	}
}

vector<PredictedItemRating> Delphi::recommend(const User& user, int topN)const {

	double maxRating = -1.0;

	for (Item& item : *(_dataset->getItems())) {

		// only consider items that user hasn't rated yet or doesn't own the content
		if (!skipItem(user, item)) {
			double predictedRating = predictRating(user, item);

			if (maxRating < predictedRating) {
				maxRating = predictedRating;
			}
			_recommendations->push_back(*new PredictedItemRating(user.getId(),
			item.getItemId(), predictedRating));
		}
		/*
		else {
			if (verbose) {
				System.out.println("Skipping item:" + item.getName());
			}
		}*/
	}

	_maxPredictedRating->insert(make_pair(user.getId(), maxRating));

	vector<PredictedItemRating> topNRecommendations =
		PredictedItemRating::getTopNRecommendations(*_recommendations, topN);

	/*
	if (verbose) {
		PredictedItemRating.printUserRecommendations(user, dataSet, topNRecommendations);
	}*/

	return topNRecommendations;
}

bool Delphi::skipItem(const User& user, const Item& item)const {
	bool skipItem = true;
	if (isUserBased()) {
		if (!user.hasItemRating(item.getItemId())) {
			skipItem = false;
		}
	}
	else {
		throw invalid_argument("contentBasedUndone!");
		/*
		if (user.getUserContent(item.getItemContent().getId()) == null) {
			skipItem = false;
		}*/
	}
	return skipItem;
}

double Delphi::predictRating(int userId, int itemId)const {
	return predictRating(*(_dataset->getUser(userId)), *(_dataset->getItem(itemId)));
}

double Delphi::predictRating(const User& user, const Item& item) const{
	switch (_type)
	{
	case USER_BASED:
		return estimateUserBasedRating(user, item);
		break;
	default:
		throw invalid_argument("unfinished!");
		break;
	}
}

double Delphi::estimateUserBasedRating(const User& user,const Item& item)const {

	double estimatedRating = user.getAverageRating();

	int itemId = item.getItemId();
	int userId = user.getId();

	double similaritySum = 0.0;
	double weightedRatingSum = 0.0;

	// check if user has already rated this item
	Rating existingRatingByUser(0, 0, 0);
	if (user.hasItemRating(item.getItemId())){
		existingRatingByUser = user.getItemRating(item.getItemId());
	}
	else {
		for (User& anotherUser : *_dataset->getUsers()) {
			// only consider users that rated this item
			if (anotherUser.hasItemRating(itemId)){
				Rating itemRating = anotherUser.getItemRating(itemId);
				/**
				* @todo describe how this generalizes to more accurate
				*       similarities
				*/
				double similarityBetweenUsers = _similarityMatrix->getValue(
					userId, anotherUser.getId());
				double ratingByNeighbor = itemRating.getRating();
				double weightedRating = similarityBetweenUsers
					* ratingByNeighbor;

				weightedRatingSum += weightedRating;
				similaritySum += similarityBetweenUsers;
			}
		}
		if (similaritySum > 0.0) {
			estimatedRating = weightedRatingSum / similaritySum;
		}
	}

	return estimatedRating;
}