#include "UserBasedSimilarity.h"
#include<sstream>

UserBasedSimilarity::UserBasedSimilarity(DataSet& ds)
	:BaseSimilarityMatrix()
{
	_id = typeid(this).name();
	//_useObjIdToIndexMapping = dataSet.isIdMappingRequired();
	calculate(ds);
}
void UserBasedSimilarity::calculate(DataSet& dataSet){
	int nUsers = dataSet.getUserCount();
	_nObj = nUsers;
	int nRatingValues = 5;  //ŒÂ–«∆¿∑÷

	_similarityValues = new double *[nUsers];
	for (int i = 0; i < nUsers; i++)
		_similarityValues[i] = new double[nUsers];

	_ratingCountMatrix = new RatingCountMatrix *[nUsers];
	for (int i = 0; i < nUsers; i++)
		_ratingCountMatrix[i] = new RatingCountMatrix[nUsers];

	stringstream ss;
	// if we want to use mapping from userId to index then generate 
	// index for every userId
		for (User uu : dataSet.getUsers()) {
			ss << uu.getId();
			string userId;
			ss >> userId;
			_idMapping->getIndex(userId);
		}

	for (int u = 0; u < nUsers; u++) {

		int userAId = getObjIdFromIndex(u);
		User userA = dataSet.getUser(userAId);

		for (int v = u + 1; v < nUsers; v++) {

			int userBId = getObjIdFromIndex(v);
			User userB = dataSet.getUser(userBId);

			RatingCountMatrix* rcm = new RatingCountMatrix(userA, userB, nRatingValues);

			int totalCount = rcm->getTotalCount();
			int agreementCount = rcm->getAgreementCount();

			if (agreementCount > 0) {

				_similarityValues[u][v] = (double)agreementCount / (double)totalCount;
			}
			else {
				_similarityValues[u][v] = 0.0;
			}
				_ratingCountMatrix[u][v] = *rcm;
		}

		// for u == v assign 1. 
		// RatingCountMatrix wasn't created for this case
		_similarityValues[u][u] = 1.0;
	}
}

UserBasedSimilarity::~UserBasedSimilarity()
{
	for (int i = 0; i < _nObj; i++){
		delete[] _similarityValues[i];
		delete[] _ratingCountMatrix[i];
	}
		delete[] _similarityValues;
		delete[] _ratingCountMatrix;
}
