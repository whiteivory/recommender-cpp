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

void main(){
	/*

	cout << u->getname();
	delete u;
	Rating r(1, 2, 3);
	cout << r;*/
	//Rating& a = *new Rating(1, 2, 4);
	//Rating& b = *new Rating(1, 3, 4);
//	a = b;
	vector<Rating> v;
	Rating a(1, 2, 3);
	v.push_back(a);
	sort(v.begin(), v.end());
}