#include<iostream>
#include<list>
#include"User.h"
#include"item.h"
#include<algorithm>
#include<vector>
using namespace std;
class B{
public:
	B(){ _b = 2; }
	int _b;
	B& operator= (const B& rhs)
	{ 
		_b = rhs._b; 
		return *this; }
};
class A{
public:
	A(){
		_bb = new B();
	}
	void setB(const B& bb) { *_bb = bb; }
private:
	B* _bb;
};

