#include "stdafx.h"
#include "CppUnitTest.h"

#include "Client.h"
#include "Rebate.h"
#include "Product.h"
#include "Order.h"

#include "LocalStorage.h"
#include "DataFactory.h"
#include "StorageFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiscountTest
{
	TEST_CLASS(DiscountCalc)
	{
	public:

		LocalStorage<Client> clientStorage;
		LocalStorage<Product> productStorage;
		LocalStorage<Rebate> rebateStorage;
		LocalStorage<Order> orderStorage;
		
		std::string clientId;
		std::string productId;
		std::string rebateId;
		std::string orderId;

		int originUnitPrice = 100;
		int items = 10;
		int flatRebate = 10;
		int finalRebatePrice = (int)(originUnitPrice * items * (100 - flatRebate) / 100.0);
		int fullPrice = originUnitPrice * items;

		TEST_METHOD_INITIALIZE(Init)
		{
			//StorageHousing::Get()->Store(&clientStorage);
			StorageHousing::Get()->Store(&rebateStorage);
			StorageHousing::Get()->Store(&productStorage);

			//*
			clientId = "mainclient";
			Client& client = clientStorage.Get(clientId);
			client.SetName(clientId);

			productId = "theProduct";
			Product& product = productStorage.Get(productId);
			product.SetName(productId);
			product.SetPrice(100);


			orderId = "100";
			Order& order = orderStorage.Get(orderId);
			order.SetAmount(items);
			order.SetClient(clientId);
			order.SetProduct(productId);
			// */

		}
		void AddRebate()
		{
			rebateId = "flat";
			Rebate& rebate = rebateStorage.Get(rebateId);
			rebate.SetName("Some percent");
			rebate.SetPercent(flatRebate);
			rebate.SetClient(clientId);
			rebate.SetProduct(productId);

		}
		TEST_METHOD_CLEANUP(Cleanup)
		{
			//*
			clientStorage.Cleanup();
			productStorage.Cleanup();
			rebateStorage.Cleanup();
			orderStorage.Cleanup();
			// */

		}
		TEST_METHOD(CalculateFullPrice)
		{
			Order& order = orderStorage.Get(orderId);
			Assert::AreEqual(fullPrice, order.CalculatePrice());
		}
		//*
		TEST_METHOD(CalculateRebatePrice)
		{
			Order& order = orderStorage.Get(orderId);
			AddRebate();
			Assert::AreEqual(finalRebatePrice, order.CalculatePrice());
		}
		// */
	};
}