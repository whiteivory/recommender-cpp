#pragma once
#include"User.h"
#include<string>
#include<vector>
using namespace std;
class SimilarUser
{
public:
	SimilarUser(const User& u, double simi);
	~SimilarUser();
	int getFriendId()const { return _friend->getId(); }
	string getFriendName() const { return _friend->getname(); }
	double getSimilarity()const { return _similiraty; }
	User getUser()const { return *_friend; }

	static void susort(vector<SimilarUser>& vu);
	static void print(const vector<SimilarUser>&vu,const string& header);

	bool operator<(const SimilarUser& rhs) { return _similiraty < rhs._similiraty; }
	static vector<SimilarUser> getTopNFriends(vector<SimilarUser>& vu, int topN);
private:
	User* _friend;
	double _similiraty;
};

