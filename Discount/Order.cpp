#include "stdafx.h"
#include "Order.h"


Order::Order()
{
}


Order::~Order()
{
}
void Order::Free()
{
	delete this;
}

IData* __stdcall Order::Create() {
	return new Order;
}
CreateDataFn Order::Creator() const {
	return Create;
}
std::string Order::DataTitle() const
{
	return "order";
}


std::string Order::Id()
{
	return id_;
}
void Order::SetId(std::string id)
{
	id_ = id;
}

std::string Order::Product()
{
	return product_;
}
void Order::SetProduct(std::string product)
{
	product_ = product;
}

std::string Order::Client()
{
	return client_;
}
void Order::SetClient(std::string client)
{
	client_ = client;
}

int Order::Amount()
{
	return amount_;
}
void Order::SetAmount(int amount)
{
	amount_ = amount;
}

int Order::Price()
{
	return 0;
}
