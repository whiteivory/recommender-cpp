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
	//����������ʱ����Ҫ�ˣ���Ϊ�������������ʱ����Ļ�������ֱ�ӷ�����private
	//const map<int, Rating>* getRatingsByItemIdP()const{ return ratingsByItemId; } //ע������ķ���ֵconst,�����Ա�����õĻ����ͷ���const����
	//const list<Content>* getUserContentP()const { return userContent; }//������get��Ҫ��Ϊ�� = �õģ��������ı䣬��������const
	void setUserContent(const list<Content>& c);


	double getAverageRating()const;
	void setRatings(const list<Rating>& li)const;
	list<Rating> getAllRatings()const;
	list<int> getAllItemID() const;
	bool hasItemRating(int ItemID)const;
	Rating getItemRating(int ItemID)const;
	list<Content> getUserContent()const;
	Content getUserContent(string contentId) const;

	void addUserContent(Content c);

	static vector<int> getSharedItem(const User&x, const User&y);
	vector<double> getRatingsForItemList(vector<int> itemIds)const;
	//operator
	User& operator=(const User& rhs);
private:
	void init(int id, string name, const list<Rating>&);  //ע��cpp����javaһ��������this��������constructor������Ӧ����������ʽ
	int _id;  //userID
	string _name;
protected:
	map<int, Rating>* ratingsByItemId;
	list<Content>* userContent;
};

#endif