#include "SimilarityMatrixRepository.h"
#include"UserBasedSimilarity.h"
#include<exception>
SimilarityMatrix* SimilarityMatrixRepository::load(RecommendationType type, DataSet& ds)const{
	SimilarityMatrix* m = nullptr;

	string id = getId(type, ds.getName());
	switch (type)
	{
	case USER_BASED:
		m = new UserBasedSimilarity(id, ds);
		break;
	case ITEM_BASED:
		break;
	case IMPROVED_USER_BASED:
		break;
	case ITEM_PENALTY_BASED:
		break;
	case USER_CONTENT_BASED:
		break;
	case ITEM_CONTENT_BASED:
		break;
	case USER_ITEM_CONTENT_BASED:
		break;
	default:
		throw invalid_argument("invalid type!");
		break;
	}
	return m;
}
string SimilarityMatrixRepository::getId(RecommendationType type,string datasetname){
	string classname;
	switch (type)
	{
	case USER_BASED:
		classname = "UserBased";
		break;
	case ITEM_BASED:
		break;
	case IMPROVED_USER_BASED:
		break;
	case ITEM_PENALTY_BASED:
		break;
	case USER_CONTENT_BASED:
		break;
	case ITEM_CONTENT_BASED:
		break;
	case USER_ITEM_CONTENT_BASED:
		break;
	default:
		throw invalid_argument("invalid type!");
		break;
	}
	return classname + datasetname;
}