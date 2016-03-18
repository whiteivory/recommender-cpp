#include "User.h"

void User::init(int id, string name, const list<Rating>& li){
	_id = id;
	_name = name;
	ratingsByItemId = new map < int, Rating >;
	setRatings(li);
	userContent = new list < Content >(3);
}

User::~User()
{
	delete ratingsByItemId;
	delete userContent;
}

void User::setRatings(const list<Rating>& li)const{
	ratingsByItemId->clear();
	for each (Rating ra in li)
	{
		ratingsByItemId->insert(pair<int, Rating>(ra.getItemId(), ra));
	}
}
double User::getAverageRating() const{
	double allRatingsSum = 0.0;
	list<Rating> allUserRatings = getAllRatings();
	for (Rating rating : allUserRatings) {
		allRatingsSum += rating.getRating();
	}
	return allUserRatings.size() > 0 ? allRatingsSum / allUserRatings.size() : 2.5;
}
list<Rating> User::getAllRatings() const{
	list<Rating> li;
	for (map<int, Rating>::iterator it = ratingsByItemId->begin(); it != ratingsByItemId->end(); it++){
		li.push_back(it->second);
	}
	return li;  //return by value;
}
Rating User::getItemRating(int ItemID)const{
	return ratingsByItemId->find(ItemID)->second;
}
list<Content> User::getUserContent()const{
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

void User::setUserContent(const list<Content>& li){
	*userContent = li;
}

void User::addUserContent(Content c){
	userContent->push_back(c);
}

list<int> User::getAllItemID()const{
	list<int> li;
	for (map<int, Rating>::iterator it = ratingsByItemId->begin(); it != ratingsByItemId->end(); it++){
		li.push_back(it->first);
	}
	return li;
}
vector<int> User::getSharedItem(const User& x, const User& y){
	list<int> lx = x.getAllItemID();
	list<int> ly = y.getAllItemID();
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

// ע��������������ã�����ֱ�Ӹ���ָ���ǲ��еģ������Ա����ֱ���ö�����ָ���û�б�Ҫд��������ˡ�
User& User::operator=(const User& rhs){
	*ratingsByItemId = *rhs.ratingsByItemId;
	*userContent = *rhs.userContent;
	//delete old1;ֱ�Ӹ�ֵ�Ϳ��ԣ������� =  
	//delete old2;
	return *this;
}