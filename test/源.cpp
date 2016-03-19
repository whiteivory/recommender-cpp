//A相当于Item，包含一组不同userid对这个item的评分
//B相当于Rating，同时包含一个item对象
#include<iostream>
#include<string>
using namespace std;


class A{
public:
	int _a;
	A(int a) :_a(a){};
};
class B{
	A* _ap;
public:
	B(A& a){
		_ap = &a;
	}
	~B(){

	};
};
void main(){
	A* a = new A(1);
	B b = *new B(*a);
	delete &b;
	cout << a->_a;
}