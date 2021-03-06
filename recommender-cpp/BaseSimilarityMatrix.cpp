#include "BaseSimilarityMatrix.h"
#include<sstream>

BaseSimilarityMatrix::BaseSimilarityMatrix()
{
}


BaseSimilarityMatrix::~BaseSimilarityMatrix()
{
}

int BaseSimilarityMatrix::getIndexFromObjId(int objId)const{
	stringstream ss;
	ss << objId;
	string str;
	ss >> str;
	return _idMapping->getIndex(str);
}
int BaseSimilarityMatrix::getObjIdFromIndex(int index)const{
	string tmp = _idMapping->getValue(index);
	stringstream ss(tmp);
	int r;
	ss >> r;
	return r;
}

RatingCountMatrix& BaseSimilarityMatrix::getRatingCountMatrix(int x, int y)const{
	int xx = getIndexFromObjId(x);
	int yy = getIndexFromObjId(y);

	return _ratingCountMatrix[xx][yy];
}

//Todo: �ж��Ƿ�calculate
double BaseSimilarityMatrix::getValue(int idx, int idy){
/*	if (similarityValues == null) {
		throw new IllegalStateException(
			"You have to calculate similarities first.");
	}*/

	int x = getIndexFromObjId(idx);
	int y = getIndexFromObjId(idy);

	int i, j;
	if (x <= y) {
		i = x;
		j = y;
	}
	else {
		i = y;
		j = x;
	}
	return _similarityValues[i][j];
}
//Todo:
ostream& operator<< (ostream& os, const BaseSimilarityMatrix& bm){
	return os;
}
