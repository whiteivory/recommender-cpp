#include<iostream>
#include<list>
#include"User.h"
#include"item.h"
using namespace std;

void main(){
	/*

	cout << u->getname();
	delete u;
	Rating r(1, 2, 3);
	cout << r;*/
	User* u = new User(1);
	Rating* a = new Rating(1, 2, 3);
	cout << a->getItemId();

}