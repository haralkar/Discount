#include "stdafx.h"
#include "Rebate.h"


Rebate::Rebate()
{
}


Rebate::~Rebate()
{
}

IData* __stdcall Rebate::Create() 
{ 
	return new Rebate(); 
}
CreateDataFn Rebate::Creator() const
{
	return Create; 
}

std::string Rebate::DataTitle() const 
{ 
	return "rebate"; 
}

void Rebate::Free() 
{ 
	delete this; 
}

std::string Rebate::Id() const
{ 
	return id_; 
}
void Rebate::SetId(std::string id) 
{ 
	id_ = id; 
}

std::string Rebate::Name() const
{ 
	return name_; 
}
void Rebate::SetName(std::string name) 
{ 
	name_ = name; 
}

int Rebate::Percent() const
{
	return perCent_;
}
void Rebate::SetPercent(int p)
{
	perCent_ = p;
}
int Rebate::RebateAmount(const Order&order, const Product& product ) const
{
	return (int)(order.Amount() * product.Price() * Percent()/100.0);
}

std::string Rebate::Client() const
{
	return client_;
}
void Rebate::SetClient(std::string client)
{
	client_ = client;
}
std::string Rebate::ProductId() const
{
	return product_;
}
void Rebate::SetProductId(std::string product)
{
	product_ = product;
}
