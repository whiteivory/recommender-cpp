#pragma once
#include"RecommendationType.h"
#include"DataSet.h"
#include"SimilarityMatrix.h"
#include<string>
class SimilarityMatrixRepository
{
public:
	SimilarityMatrixRepository(){}
	~SimilarityMatrixRepository(){}
	SimilarityMatrix* load(RecommendationType type,DataSet& ds)const;
	static string getId(RecommendationType type,string datasettype);
};

