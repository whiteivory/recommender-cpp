#include "Rating.h"
Rating::Rating(int userID, int itemID, int rating)
	:_userId(userID), _itemId(itemID), _rating(rating)
{
}
Rating::~Rating(){
}
bool Rating::operator==(const Rating& rhs)const{
	if ((_itemId == rhs.getItemId()) &&( _rating == rhs.getRating()) &&( _userId == rhs.getUserId()))
		return true;
	return false;
}
Rating& Rating::operator=(const Rating&rhs){
	setUserId(rhs.getUserId());
	setItemId(rhs.getItemId());
	setRating(rhs.getRating());
	return *this;
}
ostream& operator<<(ostream&os, const Rating& R){
	os << typeid(R).name() << "[userID:" << R.getUserId() << ", itemID:" << R.getItemId() << ", rating:" << R.getRating() << "]" << endl;
	return os;
}
