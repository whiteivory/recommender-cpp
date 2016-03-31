#include "User.h"

void User::init(int id, string name, const vector<Rating>& li){
	_id = id;
	_name = name;
	ratingsByItemId = new map < int, Rating >;
	setRatings(li);
	userContent = new vector < Content >(3);
	_allRatings = *new vector<Rating>();
	_allItemId = *new vector<int>();
}


User::~User()
{
	delete ratingsByItemId;
	delete userContent;
	delete &_allRatings;
	delete &_allItemId;
}

void User::setRatings(const vector<Rating>& li)const{
	ratingsByItemId->clear();
	for each (Rating ra in li)
	{
		ratingsByItemId->insert(pair<int, Rating>(ra.getItemId(), ra));
		_allRatings.push_back(ra);
	}
}
double User::getAverageRating() const{
	double allRatingsSum = 0.0;
	vector<Rating> allUserRatings = getAllRatings();
	for (Rating rating : allUserRatings) {
		allRatingsSum += rating.getRating();
	}
	return allUserRatings.size() > 0 ? allRatingsSum / allUserRatings.size() : 2.5;
}

const vector<Rating>& User::getAllRatings() const{
	if (_hasSetAllratings) return _allRatings;
	for (map<int, Rating>::iterator it = ratingsByItemId->begin(); it != ratingsByItemId->end(); it++){
		_allRatings.push_back(it->second);
	}
	_hasSetAllratings = true;
	return _allRatings;  //return by value;
}
const vector<int>& User::getAllItemID()const{
	if (_hasSetAllItemId) return _allItemId;
	for (map<int, Rating>::iterator it = ratingsByItemId->begin(); it != ratingsByItemId->end(); it++){
		_allItemId.push_back(it->first);
	}
	_hasSetAllItemId = true;
	return _allItemId;
}

//assert hasItemRating()
Rating User::getItemRating(int ItemID)const{
	return ratingsByItemId->find(ItemID)->second;
}

vector<Content> User::getUserContent()const{
	return *userContent;
}
Content User::getUserContent(string contentId)const{
	Content tmp;
	for each (Content c in *userContent)
	{
		if (c.getId().compare(contentId) == 0)
		{
			tmp = c;
		}
	}
	return tmp;
}

void User::setUserContent(const vector<Content>& li){
	*userContent = li;
}

void User::addUserContent(Content c){
	userContent->push_back(c);
}


vector<int> User::getSharedItem(const User& x, const User& y){
	vector<int> lx = x.getAllItemID();
	vector<int> ly = y.getAllItemID();
	vector<int> r;
	for each (int x in lx)
	{
		for each (int y in ly)
		{
			if (x == y)
			{
				r.push_back(x);
			}
		}
	}
	return r;
}
bool User::hasItemRating(int ItemID) const{
	if (ratingsByItemId->count(ItemID))
		return true;
	return false;
}
vector<double> User::getRatingsForItemList(vector<int> itemIds)const{
	vector<double> ratings;
	Rating tmp(0, 0, 0);
	for each (int x in itemIds)
	{
		if (hasItemRating(x)){
			tmp = getItemRating(x);
			ratings.push_back(tmp.getRating());
		}
		else
			throw invalid_argument("itemid not found!");
	}
	return ratings;
}

// 注意这个函数的运用，由于直接复制指针是不行的，如果成员变量直接用对象不用指针就没有必要写这个函数了。
User& User::operator=(const User& rhs){
	*ratingsByItemId = *rhs.ratingsByItemId;
	*userContent = *rhs.userContent;
	//delete old1;直接赋值就可以，有重载 =  
	//delete old2;
	return *this;
}