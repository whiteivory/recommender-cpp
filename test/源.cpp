#include<iostream>
#include<string>
using namespace std;

class A{
public:
	int _a;
	string _s;
	A(){}
};

void main(){
	A a;
	cout << a._a << " " << a._s;
}