#pragma once
#include "SimilarityMatrix.h"
#include<string>
using namespace std;

class BaseSimilarityMatrix :
	public SimilarityMatrix
{
protected:
	string id;
	double** similarityValues;
	RatingCountMatrix** ratingCountMatrix;
	bool keepRatingCountMatrix = false;

	protected ValueToIndexMapping idMapping = new ValueToIndexMapping();

public:
	BaseSimilarityMatrix();
	virtual ~BaseSimilarityMatrix();
};

