#pragma once
#include "Recommender.h"
#include"RecommendationType.h"
#include "DataSet.h"
class Delphi :
	public Recommender
{
private:
	RecommendationType type;
	static const double DEFAULT_SIMILARITY_THRESHOLD;
	static const double MAX_RATING;
	DataSet* _dataset;

public:
	Delphi();
	~Delphi();
};

