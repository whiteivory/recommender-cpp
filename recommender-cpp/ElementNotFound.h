#pragma once
#include<exception>
using namespace std;

class ElementNotFound:public exception{
public:
	const char* what()const throw(){
		return "element not found ";
	}
};