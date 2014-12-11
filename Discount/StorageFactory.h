#pragma once
#include <map>
#include "IDataStorage.h"
using namespace std;

class StorageHousing
{
public:
	static StorageHousing* Get()
	{
		static StorageHousing instance;
		return &instance;
	}

	template <class Storage>
	void Store(Storage* store){
		//stored_ = 
		store_[store->DataTitle()] = store;
	}
	template <class Storage>
	IDataStorage<Storage>* Retrieve(){
		Storage s;
		auto p = (IDataStorage<Storage>*)(store_[s.DataTitle()]);
		return p;
	}
private:
	map<std::string, void*> store_;
	//template <class Storage>	Storage* stored_;
};

class StorageFactory
{
private:
	StorageFactory();
	virtual ~StorageFactory();
	StorageFactory(const StorageFactory&) { }
	StorageFactory &operator=(const StorageFactory&) { return *this; }

	map<string, CreateDataFn> FactoryMap_;
public:
	static StorageFactory* Instance()
	{
		static StorageFactory instance;
		return &instance;
	}
	template<class T> 
	IDataStorage<T>* Get() { return NULL; }

	void Register(const string &dataName, CreateDataFn pfnCreate);
	IData *CreateFactory(const string &dataName);
};

