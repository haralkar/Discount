#pragma once
#include "IDataStorage.h"
#include "IData.h"
#include "DataFactory.h"

#include "Client.h"

//template <class T>
class LocalStorage : public IDataStorage
{
public:
	LocalStorage()
	{
		DataFactory* df = DataFactory::Get();
		df->Register("client", Client::Create);
	}
	//virtual ~LocalStorage();

	virtual IData* Get(std::string name)
	{
		DataFactory* df = DataFactory::Get();
		return df->CreateDataInstance(name);
	}
protected:
	//DataFactory factory_;
};

