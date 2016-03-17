
#include<list>
#include<map>
#include<string>
#include<utility>
#include<sstream>
#include"Rating.h"
#include"content.h"
#include<vector>
#include<exception>
using namespace std;

class User
{
public:
	User(int id, string name, const list<Rating>&li) { init(id, name, li); }
	User(int id, string name) { list<Rating> li; init(id, name, li); }
	User(int id) {
		list<Rating> li;
		stringstream ss;
		ss << id;
		string tmp = ss.str();
		init(id, tmp,li);
	}
	~User();
	int getId()const{ return _id; }
	string getname() const { return _name; }
	double getAverageRating()const;
	void setRatings(const list<Rating>& li)const;
	list<Rating> getAllRatings()const;
	list<int> getAllItemID() const;
	bool hasItemRating(int ItemID)const;
	Rating getItemRating(int ItemID)const;
	list<Content> getUserContent()const;
	Content getUserContent(string contentId) const;
	void setUserContent(list<Content> c);
	void addUserContent(Content c);

	static vector<int> getSharedItem(const User&x, const User&y);
	vector<double> getRatingsForItemList(vector<int> itemIds)const;
private:
	void init(int id, string name, const list<Rating>&);  //注意cpp不像java一样可以用this调用重载constructor，所以应该用这种形式
	int _id;
	string _name;

protected:
	map<int, Rating>* ratingsByItemId;
	list<Content>* userContent;
};
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
		if (c.getId().compare(contentId)==0)
		{
			tmp = c;
		}
	}
	return tmp;
}

void User::setUserContent(list<Content> li){
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
			if (x==y)
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
	Rating tmp;
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
