//A�൱��Item������һ�鲻ͬuserid�����item������
//B�൱��Rating��ͬʱ����һ��item����
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