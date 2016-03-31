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
	vector<int> recs;
	eResult = xdc.LoadFile("data/users.xml");
	XMLCheckResult(eResult);
	XMLElement* proot = xdc.FirstChildElement();
	XMLElement* user = proot->FirstChildElement("User");
	while (user != nullptr){
		User mu;
		string userId, userName;
		
		userId = user->FirstChildElement("UserId")->GetText();
		userName = user->FirstChildElement("UserName")->GetText();
		XMLElement* first = user->FirstChildElement("Rating");
		while (first != nullptr){
			int rec;
			first->QueryIntText(&rec);
			recs.push_back(rec);
			first = first->NextSiblingElement("Rating");
		}
		for (int i = 0; i < recs.size(); i++){
			cout << recs[i] << " ";
		}
		user = user->NextSiblingElement("User");
	}

}
