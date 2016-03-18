#ifndef _CONTENT_H_
#define _CONTENT_H_
#include<string>
using namespace std;
class Content{
private:
	string _id;
public:
	string getId() const{ return _id; }
};
#endif