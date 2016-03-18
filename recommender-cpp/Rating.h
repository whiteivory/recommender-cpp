#ifndef _RATING_H_
#define _RATING_H_
#include"item.h"
#include<iostream>
using namespace std;
class Rating
{
public:
	Rating(int ,int ,int);
	~Rating(){}
	//get set
	int getItemId()const{ return _itemId; }
	int getRating() const{ return _rating; }
	int getUserId()const{ return _userId; }
	Item getItem()const{ return _item; }
	void setUserId(int userID){ _userId = userID; }
	void setItemId(int itemId) { _itemId = itemId; }
	void setRating(int rating){ _rating = rating; }
	void setItem(Item item) { _item = item; }
	//
	bool operator==(const Rating&)const;
	Rating& operator=(const Rating&);
protected:
	Item _item;
private:
	int _userId;
	int _rating;
	int _itemId;
};


#endif