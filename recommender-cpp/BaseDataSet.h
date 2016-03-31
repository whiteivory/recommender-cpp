#pragma once
#include "DataSet.h"
#include "User.h"
#include"Rating.h"
#include"Item.h"
#include<unordered_map>
#include<vector>

class BaseDataSet :
	public DataSet
{
protected:
	vector<Rating>* _allRatings;
	unordered_map<int, User>* _allUsers;
	vector<User>* _allUsersOnly;
	unordered_map<int, Item>* _allItems;
	vector<Item>* _allItemsOnly;
	unordered_map<int, vector<Rating> >* _raingsByUserId;
public://get
	Item* getItem(int itemId)const {
		return &(*(_allItems->find(itemId))).second;
	}

	double getAverageItemRating(int itemId) const{
		return (*getItem(itemId)).getAverateRating();
	}

	double getAverageUserRating(int userId) const{
		return (*getUser(userId)).getAverageRating();
	}
	User* getUser(int userId)const {
		return &(*(_allUsers->find(userId))).second;
	}
	int getUserCount() const{
		return _allUsers->size();
	}
	virtual vector<User>* getUsers() const;
	mutable bool _uflag = false;
	virtual vector<Item>* getItems() const;
	mutable bool _iflag = false;
	//total of availavle item ratings
	virtual int getRatingsCount()const{ return _allRatings->size(); }
	virtual vector<Rating>* getRatings()const{ return _allRatings; }
	virtual int getItemCount() const{ return _allItems->size(); }
public:
	BaseDataSet();
	~BaseDataSet();
	virtual bool isIdMappingRequired()const{ return false; }

	virtual int loadData() = 0;//根据从文件读或者从数据库读来进行继承
};

