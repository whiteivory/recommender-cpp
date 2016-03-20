#pragma once

#include<vector>
#include"Rating.h"
#include<string>
#include"User.h"
#include"Item.h"
using namespace std;
class DataSet{
public:
	virtual int getRatingCount()const = 0;  //total of availavle item ratings
	virtual int getUserCount()const = 0; //number of availabel user
	virtual int getItemCount() const= 0; // item
	virtual vector<Rating> getRatings() const= 0;
	virtual double getAverageItemRating()const = 0;
	virtual double getAverageUserRating()const = 0;
	virtual string getName()const = 0;
	
	virtual User getUser(int userId) const = 0;
	virtual Item getItem(int itemId) const = 0;
	virtual vector<User> getUsers() const = 0;
	virtual vector<Item> getItems() const = 0;
	/*return true if ids aren't in sequence and can't be used as array indexes.
     * false if user or items ids can be treated as sequences that start with 1. 
     * In this case index will be derived from id: index = id - 1.
	*/
	virtual bool isIdMappingRequired()const = 0;

	/*
	* For content-based dataset returns array of terms that represent document
	* space.
	*/
	virtual vector<string> getAllItems() const = 0;
};