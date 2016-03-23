#pragma once
#include<string>
#include"RatingCountMatrix.h"
using namespace std;
class SimilarityMatrix
{
public:
	/**
	* Returns matrix of similarities. For user-oriented methods it represents
	* similarities between users and for item-oriented methods the matrix
	* represents similarities between items.
	*
	* @return similarity matrix
	*/
	virtual double** getSimilarityMatrix() = 0;

	/**
	* Returns similarity value between two objects identified by their IDs.
	*
	* @param idX
	* @param idY
	* @return
	*/
	virtual double getValue(int idX, int idY) = 0;

	/**
	* Similarity matrix id.
	* @return
	*/
	virtual string getId()const = 0;

	virtual RatingCountMatrix& getRatingCountMatrix(int idX, int idY)const = 0;

	virtual bool isRatingCountMatrixAvailable()const = 0;

	virtual ~SimilarityMatrix() {};
};

