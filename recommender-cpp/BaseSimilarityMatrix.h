//Todo:1\operator <<  
//2\判断是否calculate
#pragma once
#include "SimilarityMatrix.h"
#include"ValueToIndexMapping.h"
#include"DataSet.h"
#include<string>
using namespace std;

class BaseSimilarityMatrix :
	public SimilarityMatrix
{
	friend ostream& operator<< (ostream& os, const BaseSimilarityMatrix& bm);
protected:
	string _id;
	bool _keepRatingCountMatrix = false;
	int _nObj;
	double** _similarityValues;
	RatingCountMatrix** _ratingCountMatrix;
	ValueToIndexMapping* _idMapping = new ValueToIndexMapping();  //由于是用二维数组实现，所以index必须是连续整数，所以用map来进行映射。
	BaseSimilarityMatrix();

	int getIndexFromObjId(int objId);//obj可以是item，可以是User
	int getObjIdFromIndex(int index);


public:
	RatingCountMatrix& getRatingCountMatrix(int x, int y);
	double getValue(int idx, int idy);
	virtual void calculate(DataSet& ds) = 0;
	virtual ~BaseSimilarityMatrix();
};

