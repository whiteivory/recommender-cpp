#include "XMLDataSet.h"
#include "tinyxml2.h"
using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult;}
#endif
XMLDataSet::XMLDataSet()
{
}


XMLDataSet::~XMLDataSet()
{
}
//load from users.xml items.xml ratings.xml
/*
<Users>
<User>
<UserId>1</UserId>
<UserName>tttt</UserName>
<Rating>
<PageId>1000</PageId>
<star>2</star>
</Rating>
<Rating>
<PageId>1003</PageId>
<star>2</star>
</Rating>
<Rating>
<PageId>1002</PageId>
<star>5</star>
</Rating>
</User>*/
//	unordered_map<int, User>* _allUsers;
//vector<User>* _allUsersOnly;
int XMLDataSet::loadData(){
	//load user
	XMLDocument xdc;
	XMLError eResult;
	eResult = xdc.LoadFile("data/users.xml");
	XMLCheckResult(eResult);
	XMLElement* proot = xdc.FirstChildElement();
	XMLElement* user = proot->FirstChildElement("User");
	while (user != nullptr){
		//User mu;
		string  userName;
		int userId;
		vector<Rating> recs;
		user->FirstChildElement("UserId")->QueryIntText(&userId);
		userName = user->FirstChildElement("UserName")->GetText();
		XMLElement* first = user->FirstChildElement("Rating");
		while (first != nullptr){
			int itemId, rating;
			first->FirstChildElement("PageId")->QueryIntText(&itemId);
			first->FirstChildElement("star")->QueryIntText(&rating);
			Rating ra(userId, itemId, rating);
			recs.push_back(ra);
			first = first->NextSiblingElement("Rating");
		}
		User mu(userId, userName, recs);
		pair<int, User> p = make_pair(userId, mu);
		_allUsers->insert(p);
		_allUsersOnly->push_back(mu);

		user = user->NextSiblingElement("User");
	}
	xdc.Clear();

	//load items
	/*	unordered_map<int, Item>* _allItems;
	vector<Item>* _allItemsOnly;
	*/
	eResult = xdc.LoadFile("data/items.xml");
	XMLCheckResult(eResult);
	proot = xdc.FirstChildElement(); //<Items>
	XMLElement* item = proot->FirstChildElement("Item");
	while (item != nullptr){
		int itemId;
		vector<Rating> recs;
		item->FirstChildElement("ItemId")->QueryIntText(&itemId);
		XMLElement* first = item->FirstChildElement("Rating");
		while (first != nullptr){
			int userId, rating;
			first->FirstChildElement("UserId")->QueryIntText(&userId);
			first->FirstChildElement("star")->QueryIntText(&rating);
			Rating ra(userId, itemId, rating);
			recs.push_back(ra);
			first = first->NextSiblingElement("Rating");
		}
		Item mi(itemId, "", recs);
		pair<int, Item> p = make_pair(itemId, mi);
		_allItems->insert(p);
		_allItemsOnly->push_back(mi);

		item = item->NextSiblingElement("Item");
	}
	xdc.Clear();

	//load Ratings.xml
	eResult = xdc.LoadFile("data/ratings.xml");
	XMLCheckResult(eResult);
	proot = xdc.FirstChildElement(); 
	XMLElement* rating = proot->FirstChildElement("Rating");
	while (rating!=nullptr)
	{
		int userId, itemId, star;
		rating->FirstChildElement("UserId")->QueryIntText(&userId);
		rating->FirstChildElement("ItemId")->QueryIntText(&itemId);
		rating->FirstChildElement("Star")->QueryIntText(&star);
		Rating r(userId, itemId, star);
		_allRatings->push_back(r);
		rating = rating->NextSiblingElement("Rating");

	}
}
