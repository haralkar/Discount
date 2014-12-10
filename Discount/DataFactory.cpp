#include "stdafx.h"
#include "DataFactory.h"


DataFactory::DataFactory()
{
}


DataFactory::~DataFactory()
{
	FactoryMap_.clear();
}

void DataFactory::Register(const string &dataName, CreateDataFn pfnCreate)
{
	FactoryMap_[dataName] = pfnCreate;
}
IData *DataFactory::CreateDataInstance(const string &DataName)
{
	auto it = FactoryMap_.find(DataName);
	if (it != FactoryMap_.end())
		return it->second();
	return NULL;
}