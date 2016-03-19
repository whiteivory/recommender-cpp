#include"Item.h"

Item::Item(int id, string name,const list<Rating>& li)
	:_itemId(id), _name(name)
{
	_ratingsByUserId = new unordered_map<int, Rating>(li.size());
	for (list<Rating>::const_iterator it = li.begin(); it != li.end(); it++){
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
	*_ratingsByUserId = *rhs._ratingsByUserId;
}
Item::~Item(){
	delete _ratingsByUserId;
}
Item& Item::operator=(const Item& rhs){
	_itemId = rhs._itemId;
	_name = rhs._name;
	return *this;
}
