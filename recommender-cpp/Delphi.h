#pragma once
#include "Recommender.h"
#include"RecommendationType.h"
class Delphi :
	public Recommender
{
private:
	RecommendationType type;
	static const double DEFAULT_SIMILARITY_THRESHOLD;
	static const double MAX_RATING;

public:
	Delphi();
	~Delphi();
};

