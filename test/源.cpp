//A�൱��Item������һ�鲻ͬuserid�����item������
//B�൱��Rating��ͬʱ����һ��item����
#include<iostream>
#include<string>
using namespace std;


class A{//������
public:
	virtual void foo() = 0;
};
class B{
public:
	A getA();
};
void main(){
	int *a = new int(1);
	cout << a[2];
}