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
	int *a = new int(1);
	cout << a[2];
}