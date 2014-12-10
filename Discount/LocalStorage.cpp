#include "stdafx.h"
#include "LocalStorage.h"

IData* LocalStorage::Get(std::string name)
{
	DataFactory* df = DataFactory::Get();
	return df->CreateDataInstance(name);
}
IData* LocalStorage::Get(std::string name, std::string id)
{
	IData* d = Get(name);
	if (!d)
	{
		return NULL;
	}
	d->SetId(id);
	return d;
}


