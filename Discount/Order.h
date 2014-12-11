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


	virtual std::string Id() const;
	virtual void SetId(std::string id);

	virtual std::string ProductId() const ;
	virtual void SetProduct(std::string name);

	virtual std::string ClientId() const;
	virtual void SetClient(std::string);

	virtual int Amount() const;
	virtual void SetAmount(int p);

	virtual void SetPrice();
	virtual int CalculatePrice() const;
	virtual int Price() const;

private:
	std::string id_;
	std::string product_;
	std::string client_;
	int amount_;
	int price_;
};

