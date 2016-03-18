#include<iostream>
#include<list>
#include"User.h"

using namespace std;
class B{
public:
	B(){ _b = 1; }
	int _b;
	B& operator= (const B& rhs){
		return *this;
	}
};
class A{
public:
	A(){
		_p = new int[5];
		for (int i = 0; i < 5; i++)
			_p[i] = i;
	}
	A(const A& rhs){
		_p = new int[5];
		for (int i = 0; i < 5; i++)
			_p[i] = rhs._p[i];
	}
	~A(){ delete[] _p; }
	int *_p;
	B b;
};

class Matrix{
public:
	Matrix(int row,int col):_row(row),_col(col){
		_pmat = new double[_row*_col];
	}
	~Matrix(){ delete _pmat;}
	Matrix(const Matrix& rhs){
		_pmat = rhs._pmat;
	}
	Matrix& operator=(const Matrix rhs){
		_pmat = rhs._pmat;
	}
private:
	int _row, _col;
	double* _pmat;
};

void main(){
	/*
	User* u = new User(1);
	cout << u->getname();
	delete u;
	Rating r(1, 2, 3);
	cout << r;*/

	
	A b;
	A* a = new A();
		(*a)._p[2] = 100;
		b = *a;
		delete[] a;
	cout << b._p[2];
}