#pragma once
#include "BaseDataSet.h"
class XMLDataSet :
	public BaseDataSet
{
public:
	XMLDataSet();
	~XMLDataSet();
	virtual int loadData();
};

