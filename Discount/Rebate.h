#pragma once
#include "IData.h"
#include "Order.h"
#include "Product.h"

class Rebate : public IData
{
public:
	Rebate();
	virtual ~Rebate();
	void Free();

	static IData* __stdcall Create();
	virtual CreateDataFn Creator() const;
	virtual std::string DataTitle() const final;


	virtual std::string Id() const;
	virtual void SetId(std::string id);

	virtual std::string Name() const ;
	virtual void SetName(std::string name);

	virtual int Percent() const;
	virtual void SetPercent(int p);

	virtual int RebateAmount(const Order&, const Product& ) const;

	virtual std::string Client() const;
	virtual void SetClient(std::string );

	virtual std::string ProductId() const ;
	virtual void SetProductId(std::string);


private:
	std::string id_;
	std::string name_;
	std::string client_;
	std::string product_;
	int perCent_;
};

