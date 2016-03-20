#pragma once
#include"User.h"
#include"Item.h"
using namespace std;

class RatingCountMatrix
{
private:
	int **_matrix;
	int _nRatingValues;

	void calculate(const User& u1, const User& u2);
public:
	RatingCountMatrix(const User& u1,const User& u2,int nRatingValues);
	int getTotalCount()const;
	int getAgreementCount() const;
	
	~RatingCountMatrix();
};

