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


std::string Order::Id() const
{
	return id_;
}
void Order::SetId(std::string id)
{
	id_ = id;
}

std::string Order::ProductId() const
{
	return product_;
}
void Order::SetProduct(std::string product)
{
	product_ = product;
}

std::string Order::ClientId() const
{
	return client_;
}
void Order::SetClient(std::string client)
{
	client_ = client;
}

int Order::Amount() const
{
	return amount_;
}
void Order::SetAmount(int amount)
{
	amount_ = amount;
}

int Order::CalculatePrice() const
{
	auto products = StorageHousing::Get()->Retrieve<Product>();
	auto product = products->Get(ProductId());

	auto rebates = StorageHousing::Get()->Retrieve<Rebate>();

	int price = product.Price() * amount_;
	for (const auto& r : rebates->All())
	{
		if (r.second->Client() == ClientId() && r.second->ProductId() == ProductId())
		{
			int rebate = r.second->RebateAmount(*this, product);
			price -= rebate;
			break;
		}
	}
	return price;
}
void Order::SetPrice()
{
	price_ = CalculatePrice();
}

int Order::Price() const
{
	return price_;
}
