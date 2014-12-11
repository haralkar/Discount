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
	//auto retrieved = StorageHousing::Get()->Retrieve<Client>();
	auto products = StorageHousing::Get()->Retrieve<Product>();
	auto product = products->Get(ProductId());

	auto rebates = StorageHousing::Get()->Retrieve<Rebate>();
	// find first rebate:
	bool hasRebate = false;
	int rebate = 0;
	for (const auto& r : rebates->All())
	{
		if (r.second->Client() == ClientId() && r.second->Product() == ProductId())
		{
			rebate = r.second->Percent();
			hasRebate = true;
			break;
		}
	}
	int price_ = product.Price() * amount_;
	if (hasRebate)
	{
		price_ -= (int)(rebate / 100.0 * price_);
	}

	return price_;
}
int Order::Price() const
{
	return 0;// price_*amount_;
}
