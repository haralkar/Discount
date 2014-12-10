#pragma once
#include <string>

#include "IData.h"
//template <class T>
class IDataStorage
{
public:

//	IDataStorage()
//	{
//	}

//	~IDataStorage()
//	{
//	}
	virtual IData* Get(std::string name) = 0;
};

