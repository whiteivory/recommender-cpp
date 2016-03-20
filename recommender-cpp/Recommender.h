#pragma once

#include"User.h"
#include"SimilarUser.h"
#include"PredictedItemRating.h"
#include<vector>
using namespace std;

class Recommender{
public:
	virtual ~Recommender() {};
	virtual vector<PredictedItemRating> recommend(const User& u) const = 0;
	virtual vector<PredictedItemRating> recommend(const User& u, int topN) const = 0;
	virtual double predictRating(const User& u, const Item& i) const = 0;

	virtual vector<SimilarUser> findSimilarUser(const User& u)const = 0;
	virtual vector<SimilarUser> findSimilarUser(const User& u, int topN) const = 0;

	virtual DataSet& getDataSet() const = 0;
	virtual double getSimilarityThreshold() = 0;

	virtual  void setSimilarityThreshold(double similarityThreshold) = 0;
};