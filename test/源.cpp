//A相当于Item，包含一组不同userid对这个item的评分
//B相当于Rating，同时包含一个item对象
#include<iostream>
#include<string>
#include"tinyxml2-master\tinyxml2.h"
#include<vector>
using namespace tinyxml2;
using namespace std;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult;}
#endif
int testGenAndSave(){
	XMLDocument xdc;
	XMLElement* proot = xdc.NewElement("Root");
	xdc.InsertFirstChild(proot);
	XMLElement* user = xdc.NewElement("User");
	proot->InsertEndChild(user);
	XMLElement* userId = xdc.NewElement("UserId");
	userId->SetText("001");
	user->InsertEndChild(userId);
	for (int i = 0; i < 3; i++){
		XMLElement* rectmp = xdc.NewElement("Rec");
		rectmp->SetText(i);
		user->InsertEndChild(rectmp);
	}
	XMLError result =  xdc.SaveFile("tmp.xml");
	XMLCheckResult(result);
}
int readXml(){
	XMLDocument xdc;
	XMLError eResult;
	vector<int> recs;
	eResult = xdc.LoadFile("tmp.xml");
	XMLCheckResult(eResult);
	XMLElement* proot = xdc.FirstChildElement();
	XMLElement* user = proot->FirstChildElement("User");
	string userId;
	userId = user->FirstChildElement("UserId")->GetText();
	cout << userId << endl;
	XMLElement* first = user->FirstChildElement("Rec");
	while (first != nullptr){
		int rec;
		first->QueryIntText(&rec);
		recs.push_back(rec);
		first = first->NextSiblingElement("Rec");
	}
	for (int i = 0; i < recs.size(); i++){
		cout << recs[i] << " ";
	}
}
int main(){

}