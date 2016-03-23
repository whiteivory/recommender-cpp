#pragma once
#include "Recommender.h"
#include"RecommendationType.h"
#include"SimilarityMatrix.h"
#include "DataSet.h"
#include<unordered_map>
class Delphi :
	public Recommender
{
private:
	RecommendationType _type;
	static const double DEFAULT_SIMILARITY_THRESHOLD;
	static const double MAX_RATING;
	DataSet* _dataset;
	SimilarityMatrix* _similarityMatrix;
	bool _verbose = true;
	double _similarityThreshold = DEFAULT_SIMILARITY_THRESHOLD;
	unordered_map<int ,double>* _maxPredictedRating;


public:
	Delphi();
	~Delphi();
};

