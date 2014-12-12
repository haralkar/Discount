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
};

