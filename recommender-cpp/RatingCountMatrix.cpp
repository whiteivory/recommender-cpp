#include "RatingCountMatrix.h"

RatingCountMatrix::RatingCountMatrix(){
	_nRatingValues = 1;
	_matrix = new int*[1];
	for (int i = 0; i < 1; i++){
		_matrix[i] = new int[1];
		for (int j = 0; j < 1; j++)
			_matrix[i][j] = 0;
	}

}
RatingCountMatrix::RatingCountMatrix(const User& u1,const User& u2,int n)
{
	_nRatingValues = n;
	_matrix = new int*[n];
	for (int i = 0; i < n; i++){
		_matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			_matrix[i][j] = 0;
	}
	calculate(u1, u2);
}
RatingCountMatrix::~RatingCountMatrix()
{
	for (int i = 0; i < _nRatingValues; i++)
		delete[] _matrix[i];
	delete[] _matrix;
}

RatingCountMatrix& RatingCountMatrix::operator=(const RatingCountMatrix&rhs){
	int** old = _matrix;
	int oldn = _nRatingValues;
	_nRatingValues = rhs._nRatingValues;
	_matrix = new int*[_nRatingValues];
	for (int i = 0; i < _nRatingValues; i++){
		_matrix[i] = new int[_nRatingValues];
		for (int j = 0; j < _nRatingValues; j++)
			_matrix[i][j] = rhs._matrix[i][j];
	}
	for (int i = 0; i < oldn; i++)
		delete[] old[i];
	delete[] old;
	return *this;
}

void RatingCountMatrix::calculate(const User& u1, const User& u2){
	for each (auto& ratingByA in *u1.getAllRatings())
	{
		if (u2.hasItemRating(ratingByA.getItemId())){
			Rating ratingByB = u2.getItemRating(ratingByA.getItemId());
			int x = ratingByA.getRating() - 1;
			int y = ratingByB.getRating() - 1;
			_matrix[x][y]++;
		}
	}
}

int RatingCountMatrix::getTotalCount() const{
	int sum = 0;
	for (int i = 0; i < _nRatingValues; i++)
		for (int j = 0; j < _nRatingValues; j++)
			if (_matrix[i][j] != 0)
				sum += _matrix[i][j];
	return sum;
}

int RatingCountMatrix::getAgreementCount() const{
	int a = 0;
	for (int i = 0; i < _nRatingValues; i++)
		a += _matrix[i][i];
	return a;
}