#pragma once
#include <string>

#include "IData.h"
template <class T>
class IDataStorage
{
public:
	
	virtual T& Get(std::string id) = 0;
	
};

//template<class T>	using CreateStorage = IDataStorage<T>* (__stdcall *)(void);
//template<class T> using DataStorage_t = IDataStorage<T>* (__stdcall *)(void);


