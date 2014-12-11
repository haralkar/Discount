#pragma once
#include <string>

#include "IData.h"
template <class T>
class IDataStorage
{
public:
	const std::string Client() const { return "client"; }

	virtual T& Get(std::string id) = 0;
	
};

