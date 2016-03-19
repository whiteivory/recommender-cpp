#ifndef _RATING_H_
#define _RATING_H_
#include<iostream>
using namespace std;
//#include"Item.h"
//class Item;
class Rating
{
public:
	Rating(int ,int ,int);
	~Rating();
	//get set
	int getItemId()const{ return _itemId; }
	int getRating() const{ return _rating; }
	int getUserId()const{ return _userId; }
//	Item* getItem()const{ return _item; }
	void setUserId(int userID){ _userId = userID; }
	void setItemId(int itemId) { _itemId = itemId; }
	void setRating(int rating){ _rating = rating; }
//	void setItem(const Item& item);
	//
	bool operator==(const Rating&)const;
	Rating& operator=(const Rating&);
//protected:  经过一些挣扎，决定去掉这个类，而把返回Item的功能存放在Item类中，根据传入的Rating，我们写代码中应该尽量减少循环依赖的出现
	//Item* _item;
private:
	int _userId;
	int _rating;
	int _itemId;
};


#endif