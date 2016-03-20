//A相当于Item，包含一组不同userid对这个item的评分
//B相当于Rating，同时包含一个item对象
#include<iostream>
#include<string>
using namespace std;


class A{//抽象类
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