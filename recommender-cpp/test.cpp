#include<iostream>
#include<list>
#include"User.h"
using namespace std;

class A {
public:
	A(int a) :_a(a){
		li = new list<int>();
	}
	int _a;
	list<int>* li;
};
class B{
public:
	B(A& a) :_aa(a){}
	A _aa;
	int _b;
};
void main(){
	A*  a = new A(1);
	a->li->clear();
	User* u = new User(1);
	delete u;
}