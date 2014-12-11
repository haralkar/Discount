#pragma once
#include "IData.h"

class Product : public IData
{
public:
	Product();
	virtual ~Product();
	void Free() { delete this; }

	virtual std::string Id();
	virtual void SetId(std::string id);

	virtual std::string Name();
	virtual void SetName(std::string name);

	virtual int Price();
	virtual void SetPrice(int price);


	static IData* __stdcall Create();
	virtual CreateDataFn Creator() const;

	virtual std::string DataTitle() const final;

private:
	std::string id_;
	std::string name_;
	int price_;
};
