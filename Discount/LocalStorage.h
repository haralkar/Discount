#pragma once
#include "IDataStorage.h"
#include "IData.h"
#include "DataFactory.h"

#include "Client.h"

template <class T>
class LocalStorage : public IDataStorage<T>
{
public:
	LocalStorage()
	{
		T t;
		DataFactory::Get()->Register(t.DataTitle(), t.Creator());
	}
	//virtual ~LocalStorage();

	virtual IData* Get(std::string name);

	virtual IData* Get(std::string name, std::string id);
};

template <class T>
inline IData* LocalStorage<T>::Get(std::string name)
{
	DataFactory* df = DataFactory::Get();
	return df->CreateDataInstance(name);
}
template <class T>
inline IData* LocalStorage<T>::Get(std::string name, std::string id)
{
	IData* d = Get(name);
	if (!d)
	{
		return NULL;
	}
	d->SetId(id);
	return d;
}
