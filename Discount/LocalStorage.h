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
		if (!initialised_)
		{
			T t;
			dataTitle_ = t.DataTitle();
			DataFactory::Get()->Register(dataTitle_, t.Creator());
			initialised_ = true;
		}
	}
	void Cleanup()
	{ 
		data_.clear(); 
		initialised_ = false; 
	}

	virtual std::string DataTitle() { return dataTitle_; }

	virtual T& Get(std::string id);
	virtual map<std::string, T*>& All() const ;

protected:
	virtual T& NewData(std::string id);

	static map < std::string, T* > data_;
	static std::string dataTitle_;
	static bool initialised_;

};
template<class T>
map < std::string, T*> LocalStorage<T>::data_;
template<class T>
bool LocalStorage<T>::initialised_ = false;
template<class T>
std::string LocalStorage<T>::dataTitle_;

template <class T>
inline T& LocalStorage<T>::NewData(std::string id)
{
	DataFactory* df = DataFactory::Get();
	T* d = static_cast<T*>(df->CreateDataInstance(dataTitle_));
	d->SetId(id);
	data_[id] = d;
	return *d;
}
template <class T>
inline T& LocalStorage<T>::Get(std::string id)
{
	auto it = data_.find(id);
	if (it != data_.end())
		return *it->second;

	T& d = NewData(id);
	return d;
}
//*
template <class T>
inline map<std::string, T*>& LocalStorage<T>::All() const
{
	return data_;
}

// */