#pragma once
#include <string>
#include <map>

#include "IData.h"

using namespace std;
template <class T>
class IDataStorage
{
public:
	virtual map<string, T*>& All() const = 0 ;
	virtual T& Get(string id) = 0;

};

//template<class T>	using CreateStorage = IDataStorage<T>* (__stdcall *)(void);
//template<class T> using DataStorage_t = IDataStorage<T>* (__stdcall *)(void);


