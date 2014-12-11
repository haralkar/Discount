#pragma once
#include <map>
#include <memory>

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
	void Cleanup(){ data_.clear();}

	//virtual ~LocalStorage();

	virtual T& Get(std::string name);

	virtual T& Get(std::string name, std::string id);
protected:
	static map < std::string, T* > data_;

};
template<class T>
map < std::string, T*> LocalStorage<T>::data_;

template <class T>
inline T& LocalStorage<T>::Get(std::string name)
{
	DataFactory* df = DataFactory::Get();
	T* d = static_cast<T*>(df->CreateDataInstance(name));
	data_[name] = d;
	return *d;
}
template <class T>
inline T& LocalStorage<T>::Get(std::string name, std::string id)
{
	auto it = data_.find(name);
	if (it != data_.end())
		return *it->second;

	T& d = Get(name);
	d.SetId(id);
	return d;
}
