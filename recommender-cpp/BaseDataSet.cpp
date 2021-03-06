#include "BaseDataSet.h"


BaseDataSet::BaseDataSet()
{
	_allUsersOnly = new vector<User>();
	_allItemsOnly = new vector<Item>();
	_allRatings = new vector<Rating>();

	_allUsers = new unordered_map<int, User>();
	_allItems = new unordered_map<int, Item>();
}


BaseDataSet::~BaseDataSet()
{
	delete _allUsersOnly;
	delete _allItemsOnly;
	delete _allRatings;

	delete _allUsers;
	delete _allItems;
}

vector<User>* BaseDataSet::getUsers() const{
	/*	if (_uflag == false){
		_uflag = true;
		for (unordered_map<int, User>::iterator it = _allUsers->begin(); it != _allUsers->end(); it++){
			_allUsersOnly->push_back(it->second);
		}
	}*/
	return _allUsersOnly;
}

vector<Item>* BaseDataSet::getItems() const{
	/*
		if (_iflag == false){
		_iflag = true;
		for (unordered_map<int, Item>::iterator it = _allItems->begin(); it != _allItems->end(); it ++ ){
			_allItemsOnly->push_back(it->second);
		}
	}
	*/
	return _allItemsOnly;
}