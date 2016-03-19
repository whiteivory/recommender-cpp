#ifndef _ITEM_H_
#define _ITEM_H_
#include<unordered_map>
#include<list>
#include"Rating.h"
using namespace std;
class Rating;
class Item
{
public:
	Item();
	Item(const Item& rhs);
	Item(int id, string name, const list<Rating>& li);
	~Item();
	Item& operator= (const Item& rhs);
private:
	int _itemId;
	string _name;
	unordered_map<int, Rating>* _ratingsByUserId;

};
#endif