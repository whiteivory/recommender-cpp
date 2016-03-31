//Todo:1\operator <<  
//2\�ж��Ƿ�calculate
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

	double** _similarityValues; //���ƾ���[x,y]�û�x���û�y�����ƶȣ��Ǹ�������һ���������ģ�Ҳ�����յ����ƶ�
	RatingCountMatrix** _ratingCountMatrix;//[x,y]��ʾ�û�x���û�y�� RatingCOuntMatrix


	ValueToIndexMapping* _idMapping = new ValueToIndexMapping();  //�������ö�ά����ʵ�֣�����index����������������������map������ӳ�䡣
	BaseSimilarityMatrix();

	int getIndexFromObjId(int objId)const;//obj������item��������User
	int getObjIdFromIndex(int index)const;

	double** getSimilarityMatrix() {
		return _similarityValues;
	}
	bool isRatingCountMatrixAvailable() const{
		return _keepRatingCountMatrix;
	}

public:
	RatingCountMatrix& getRatingCountMatrix(int x, int y)const;
	double getValue(int idx, int idy);
	virtual void calculate(DataSet& ds) = 0;
	virtual ~BaseSimilarityMatrix();
	string getId()const{ return _id; }
};

