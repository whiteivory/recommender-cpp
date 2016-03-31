#pragma once
#include "BaseDataSet.h"
using namespace std;
class XMLDataSet :
	public BaseDataSet
{
public:
	XMLDataSet();
	~XMLDataSet();
	virtual int loadData();
	virtual string getName()const{
		return "XMLDataSet";
	}
};

