// CalculateDiscounts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>

#include "LocalStorage.h"
#include "Client.h"
#include "Product.h"
#include "Rebate.h"
#include "Order.h"

#include "StorageHousing.h"

using namespace std;

LocalStorage<Client>* clientStorage;
LocalStorage<Product>* productStorage;
LocalStorage<Rebate>* rebateStorage;
LocalStorage<Order>* orderStorage;

void initFactories()
{

	clientStorage = new LocalStorage<Client>;
	string title = clientStorage->DataTitle();
	StorageHousing::Get()->Store(clientStorage);
	title = clientStorage->DataTitle();
	StorageHousing::Get()->Store(productStorage = new LocalStorage<Product>);
	StorageHousing::Get()->Store(rebateStorage = new LocalStorage<Rebate>);
	StorageHousing::Get()->Store(orderStorage = new LocalStorage<Order>);

	auto clients = StorageHousing::Get()->Retrieve<Client>();
}
void addClients(char* list[])
{
	auto clients = StorageHousing::Get()->Retrieve<Client>();

	while (*list)
	{
		auto id = string(*list); list++;
		auto name = string(*list); list++;

		Client& c = clients->Get(id);
		c.SetName(name);
	}

}
void addProducts(char* productlist[], int prices[])
{
	auto products = StorageHousing::Get()->Retrieve<Product>();
	int i = 0;
	while (*productlist)
	{
		auto id = string(*productlist); productlist++;
		auto name = string(*productlist); productlist++;
		int price = prices[i++];

		Product& p = products->Get(id);
		p.SetName(name);
		p.SetPrice(price);
	}
}
void addRebate(char* list[], int percents[])
{
	auto rebates = StorageHousing::Get()->Retrieve<Rebate>();
	int i = 0;
	while (*list)
	{
		auto id = string(*list); list++;
		auto name = string(*list); list++;
		auto client = string(*list); list++;
		auto product = string(*list); list++;
		int percent = percents[i++];

		Rebate& p = rebates->Get(id);
		p.SetName(name);
		p.SetClient(client);
		p.SetProductId(product);
		p.SetPercent(percent);
	}
}
void addOrders(char* list[], int amounts[])
{
	auto orders = StorageHousing::Get()->Retrieve<Order>();
	int i = 0;
	while (*list)
	{
		auto id = string(*list); list++;
		auto client = string(*list); list++;
		auto name = string(*list); list++;
		int amount = amounts[i++];

		Order& p = orders->Get(id);
		p.SetClient(client);
		p.SetProduct(name);
		p.SetAmount(amount);
	}
}
void addData()
{

	char* clientslist[] = { "1", "Best", "2", "Other", nullptr } ;
	addClients(clientslist);
	char* productlist[] = { "1", "Chair", "2", "Table", "3", "Stool", nullptr };
	int prices[] = { 100, 1000, 50 };
	addProducts(productlist, prices);
	char* rebatelist[] = { "1", "Flat50", "1", "1",  "2", "simple10", "1", "2",  "3", "StoolDisc", "2", "3", nullptr };
	int percent[] = { 50, 10, 5 };
	addRebate(rebatelist, percent);
	// id,client,product,
	char* orderlist[] = { "1", "1", "2",  "2", "1", "1",  "3", "2", "3", nullptr };
	int amount[] = { 1, 6, 2 };
	addOrders(orderlist, amount);

}
void SetupData()
{
	initFactories();
	addData();
}
void PrintOrderList()
{
	auto orders = StorageHousing::Get()->Retrieve<Order>();
	for (const auto& theOrder : orders->All())
	{
		Order& order = *theOrder.second;
		Client& client = clientStorage->Get(order.ClientId());
		Product& product = productStorage->Get(order.ProductId());
		order.SetPrice();
		cout << "Order from " << client.Name() << " Product " << order.Amount() << "x " << product.Name() << " price " << order.Price() << endl;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	SetupData();
	PrintOrderList();
	return 0;
}

