#pragma once
#include "IData.h"

class Product : public IData
{
public:
	Product();
	virtual ~Product();
	void Free() { delete this; }

	virtual std::string Id() { return id_; }
	virtual void SetId(std::string id) { id_ = id; }

	virtual std::string Name() { return name_; }
	virtual void SetName(std::string name) { name_ = name; }

	virtual int Price() { return price_; }
	virtual void SetPrice(int price) { price_ = price; }


	static IData* __stdcall Create() { return new Product(); }
	virtual CreateDataFn Creator() const { return Create; }

	virtual std::string DataTitle() const final { return "product"; }

private:
	std::string id_;
	std::string name_;
	int price_;
};
