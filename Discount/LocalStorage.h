#pragma once
#include "IDataStorage.h"
#include "IData.h"
#include "DataFactory.h"

#include "Client.h"

class LocalStorage : public IDataStorage
{
protected:
	//DataFactory factory_;
public:
	LocalStorage()
	{
		DataFactory* df = DataFactory::Get();
		df->Register("client", Client::Create);
	}
	//virtual ~LocalStorage();

	virtual IData* Get(std::string name);

	virtual IData* Get(std::string name, std::string id);
};

