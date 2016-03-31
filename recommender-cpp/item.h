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
	Item(int id, string name, const vector<Rating>& li);
	~Item();
	Item& operator= (const Item& rhs);
	int getItemId()const{ return _itemId; }
	string getName() const { return _name; }
	double getAverateRating()const;
	Rating getUserRating(int)const;
	void setUserRating(const Rating&);
	static vector<int> getSharedUserIds(const Item& i1, const Item& i2);
private:
	int _itemId;
	string _name;
	unordered_map<int, Rating>* _ratingsByUserId;

};
#endif