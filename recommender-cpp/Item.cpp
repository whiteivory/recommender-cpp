#include"Item.h"

Item::Item(int id, string name,const vector<Rating>& li)
	:_itemId(id), _name(name)
{
	_ratingsByUserId = new unordered_map<int, Rating>(li.size());
	for (vector<Rating>::const_iterator it = li.begin(); it != li.end(); it++){
		_ratingsByUserId->insert(make_pair(it->getItemId(), *it));
	}
}
Item::Item(){
	_itemId = 0;
	_name = "";
	_ratingsByUserId = new unordered_map<int, Rating>(3);
}
Item::Item(const Item& rhs){
	_itemId = rhs._itemId;
	_name = rhs._name;
	_ratingsByUserId = new  unordered_map<int, Rating>(*rhs._ratingsByUserId);
}
Item::~Item(){
	delete _ratingsByUserId;
}
Item& Item::operator=(const Item& rhs){
	_itemId = rhs._itemId;
	_name = rhs._name;
	return *this;
}

double Item::getAverateRating()const{
	double allRatingSum = 0.0;
	for each (auto ra in *_ratingsByUserId)
	{
		allRatingSum += ra.second.getRating();
	}
	//如果没有评分，返回0（原书是写的2.5
	return _ratingsByUserId->size() > 0 ? allRatingSum / _ratingsByUserId->size() : 0;
}

Rating Item::getUserRating(int userId)const{
	return _ratingsByUserId->find(userId)->second;
}

void Item::setUserRating(const Rating& r){
	_ratingsByUserId->insert(make_pair(r.getItemId(), r));
}
vector<int> Item::getSharedUserIds(const Item& i1, const Item& i2){
	vector<int> v;
	for each (auto pair in *(i1._ratingsByUserId))
	{
		int id = pair.first;
		if (i2._ratingsByUserId->count(id))
			v.push_back(id);
	}
	return v;
}
