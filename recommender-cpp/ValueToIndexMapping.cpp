#include "ValueToIndexMapping.h"


ValueToIndexMapping::ValueToIndexMapping()
{
	_nextIndex = 0;
	_valueMap = new unordered_map<int, string>();
	_indexMap = new unordered_map<string, int>();
	
}


ValueToIndexMapping::~ValueToIndexMapping()
{
	delete _valueMap;
	delete _indexMap;
}

int ValueToIndexMapping::getIndex(const string& str){
	int index;
	if (_indexMap->count(str))
		return _indexMap->find(str)->second;
	else
	{
		index = _nextIndex;
		_nextIndex++;
		_indexMap->insert(make_pair(str,index));
		_valueMap->insert(make_pair(index, str));
	}
}

