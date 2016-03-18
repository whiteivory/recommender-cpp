#ifndef _ITEM_H_
#define _ITEM_H_
#include<map>
#include"Rating.h"
using namespace std;
class Rating;
class Item
{
private:
	int _itemId;
	string _name;
	map<int, Rating> _ratingsByUserId;
public:
	Item(){}
	~Item(){}
};
#endif