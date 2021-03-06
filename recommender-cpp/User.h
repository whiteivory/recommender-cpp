/*
todo :当往map插入值得时候，那个容器也要插入相应的内容
*/
#ifndef _USER_H_
#define _USER_H_

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
	User(int id, string name, const vector<Rating>&li){
		init(id, name, li);
	}
	User(int id, string name) {
		vector<Rating> li; init(id, name, li);
	}
	User(int id)  {
		vector<Rating> li;
		stringstream ss;
		ss << id;
		string tmp = ss.str();
		init(id, tmp,li);
	}
	User(const User& rhs);
	~User();

	int getId()const{ return _id; }
	string getname() const { return _name; }
	//下面两行暂时不需要了，因为我忘了如果参数时本类的话，可以直接访问其private
	//const map<int, Rating>* getRatingsByItemIdP()const{ return ratingsByItemId; } //注意这里的返回值const,如果成员是引用的话，就返回const引用
	//const list<Content>* getUserContentP()const { return userContent; }//这两个get主要是为了 = 用的，不用来改变，所以声明const
	void setUserContent(const vector<Content>& c);


	double getAverageRating()const;
	void setRatings(const vector<Rating>& li)const;
	const vector<Rating>* getAllRatings()const;  //不允许改动，设置const
	const vector<int>* getAllItemID() const;
	bool hasItemRating(int ItemID)const;
	Rating getItemRating(int ItemID)const;
	vector<Content> getUserContent()const;
	Content getUserContent(string contentId) const;

	void addUserContent(Content c);

	static vector<int> getSharedItem(const User&x, const User&y);
	vector<double> getRatingsForItemList(vector<int> itemIds)const;
	//operator
	User& operator=(const User& rhs);
private:
	void init(int id, string name, const vector<Rating>&);  //注意cpp不像java一样可以用this调用重载constructor，所以应该用这种形式
	int _id;  //userID
	string _name;
protected:
	map<int, Rating>* ratingsByItemId;
	vector<Content>* userContent;
private://由于这两个只在调用get函数的时候才生成，所以不设置成protected
	mutable vector<Rating>* _allRatings;
	mutable bool _hasSetAllratings = false;  //mutable的运用
	mutable vector<int>* _allItemId;
	mutable bool _hasSetAllItemId = false;
};

#endif