#include "stdafx.h"
#include "StorageFactory.h"


StorageFactory::StorageFactory()
{
}


StorageFactory::~StorageFactory()
{
	FactoryMap_.clear();
}

void StorageFactory::Register(const string &dataName, CreateDataFn pfnCreate)
{
	FactoryMap_[dataName] = pfnCreate;
}
IData *StorageFactory::CreateFactory(const string &DataName)
{
	auto it = FactoryMap_.find(DataName);
	if (it != FactoryMap_.end())
		return it->second();
	return NULL;
}