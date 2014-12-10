#pragma once
#include <map>
#include "IData.h"

using namespace std;

typedef IData* (__stdcall *CreateDataFn)(void);

class DataFactory
{
private:
	DataFactory();
	DataFactory(const DataFactory &) { }
	DataFactory &operator=(const DataFactory &) { return *this; }

	map<string, CreateDataFn> FactoryMap_;
public:
	~DataFactory();

	static DataFactory *Get()
	{
		static DataFactory instance;
		return &instance;
	}

	void Register(const string &dataName, CreateDataFn pfnCreate);
	IData *CreateDataInstance(const string &dataName);
};
