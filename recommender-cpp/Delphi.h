#pragma once
#include "Recommender.h"
#include"RecommendationType.h"
#include"SimilarityMatrix.h"
#include "DataSet.h"
#include<unordered_map>
#include"SimilarUser.h"
class Delphi :
	public Recommender
{
private:
	RecommendationType _type;
	static const double DEFAULT_SIMILARITY_THRESHOLD;
	static const double MAX_RATING;
	DataSet* _dataset;
	virtual DataSet* getDataSet() const { return _dataset; }
	SimilarityMatrix* _similarityMatrix;
	bool _verbose = true;
	double _similarityThreshold = DEFAULT_SIMILARITY_THRESHOLD;

	virtual double getSimilarityThreshold()const { return _similarityThreshold; }
	virtual  void setSimilarityThreshold(double similarityThreshold) { _similarityThreshold = similarityThreshold; }
	unordered_map<int ,double>* _maxPredictedRating;

	vector<SimilarUser>* _similarUsers;
	vector<PredictedItemRating>* _recommendations;

	bool isUserBased()const {
		return _type == RecommendationType::IMPROVED_USER_BASED || _type == RecommendationType::USER_BASED || _type == RecommendationType::USER_CONTENT_BASED || _type == RecommendationType::USER_ITEM_CONTENT_BASED;
	}

	bool skipItem(const User& user, const Item& item)const;
	double estimateUserBasedRating(const User& user, const Item& item)const;
public:
	Delphi(DataSet& ds, RecommendationType type);
	void findFriendsBasedOnUserSimilarity(const User& user)const;
	vector<PredictedItemRating> recommend(const User& user)const{ return recommend(user, 5); }
	vector<PredictedItemRating> recommend(const User& user, int topN)const;
	virtual double predictRating(const User& u, const Item& i) const;
	double predictRating(int userId, int itemId)const;
	vector<SimilarUser> findSimilarUsers(const User& user)const{ return findSimilarUsers(user, 5); }
	vector<SimilarUser> findSimilarUsers(const User& user, int topN)const;
	~Delphi();
};

