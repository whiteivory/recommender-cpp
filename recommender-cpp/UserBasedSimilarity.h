#pragma once
#include "BaseSimilarityMatrix.h"
#include"DataSet.h"
#include<string>
using namespace std;
class UserBasedSimilarity :
	public BaseSimilarityMatrix
{

public:
	UserBasedSimilarity(DataSet& ds);
	~UserBasedSimilarity();
	void calculate(DataSet& ds);
};

