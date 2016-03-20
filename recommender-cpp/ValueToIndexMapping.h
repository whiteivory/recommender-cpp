#pragma once
#include<unordered_map>
using namespace std;
class ValueToIndexMapping
{
private:
	int _nextIndex = 0;
	unordered_map<int, string>* _valueMap;
	unordered_map<string, int>* _indexMap;

public:
	ValueToIndexMapping();
	~ValueToIndexMapping();
	string getValue(int index)const{ return _valueMap->find(index)->second; }
	int getIndex(const string& str);
	int getSize()const{ return _valueMap->size(); }
};

