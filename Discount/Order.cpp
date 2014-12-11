#include "stdafx.h"
#include "Order.h"

#include "Client.h"
#include "Product.h"
#include "Rebate.h"
#include "StorageFactory.h"

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

std::string Order::ProductId()
{
	return product_;
}
void Order::SetProduct(std::string product)
{
	product_ = product;
}

std::string Order::ClientId()
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

int Order::CalculatePrice() 
{
	auto products = StorageHousing::Get()->Retrieve<Product>();
	auto rebates = StorageHousing::Get()->Retrieve<Rebate>();
	//auto retrieved = StorageHousing::Get()->Retrieve<Client>();
	auto product = products->Get(ProductId());

	return product.Price() * amount_;
}
int Order::Price() const
{
	return 0;// price_*amount_;
}
