#pragma once
#include "IData.h"
class Order :
	public IData
{
public:
	Order();
	virtual ~Order();
	void Free();

	static IData* __stdcall Create();
	virtual CreateDataFn Creator() const;
	virtual std::string DataTitle() const final;


	virtual std::string Id();
	virtual void SetId(std::string id);

	virtual std::string ProductId();
	virtual void SetProduct(std::string name);

	virtual std::string ClientId();
	virtual void SetClient(std::string);

	virtual int Amount();
	virtual void SetAmount(int p);

	virtual int CalculatePrice();
	virtual int Price() const;

private:
	std::string id_;
	std::string product_;
	std::string client_;
	int amount_;
	int price_;
};

