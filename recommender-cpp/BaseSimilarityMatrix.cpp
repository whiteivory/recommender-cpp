#include "BaseSimilarityMatrix.h"
#include<sstream>

BaseSimilarityMatrix::BaseSimilarityMatrix()
{
}


BaseSimilarityMatrix::~BaseSimilarityMatrix()
{
}

int BaseSimilarityMatrix::getIndexFromObjId(int objId){
	stringstream ss;
	ss << objId;
	string str;
	ss >> str;
	return _idMapping->getIndex(str);
}
int BaseSimilarityMatrix::getObjIdFromIndex(int index){
	stringstream ss(_idMapping->getValue(index));
	int r;
	ss >> r;
	return r;
}

RatingCountMatrix& BaseSimilarityMatrix::getRatingCountMatrix(int x, int y){
	int xx = getIndexFromObjId(x);
	int yy = getIndexFromObjId(y);

	return _ratingCountMatrix[xx][yy];
}

//Todo: ≈–∂œ «∑Òcalculate
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

}