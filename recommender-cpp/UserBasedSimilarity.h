#pragma once
#include "BaseSimilarityMatrix.h"
#include"DataSet.h"
#include<string>
using namespace std;
class UserBasedSimilarity :
	public BaseSimilarityMatrix
{

public:
	UserBasedSimilarity(string Id,DataSet& ds);
	~UserBasedSimilarity();
	void calculate(DataSet& ds);
};

