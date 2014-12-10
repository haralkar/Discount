#include "stdafx.h"
#include "CppUnitTest.h"

#include "Client.h"
#include "LocalStorage.h"
#include "DataFactory.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiscountTest
{		
	TEST_CLASS(Discount)
	{
	public:
		
		TEST_METHOD(DataStorage)
		{
			LocalStorage<Client> storage;
			Assert::IsTrue(true);
		}
		TEST_METHOD(LocalStorageGetShould)
		{
			LocalStorage<Client> storage;
			Client& c = storage.Get(storage.Client());
			//Assert::IsNotNull(c);
			//c->Free();
		}
/*
		TEST_METHOD(StorageShouldSupplyIterator)
		{
			LocalStorage storage;
			Client* c = (Client*)storage.Get("client");
			Assert::IsNotNull(c);
			auto reader = storage.GetReader("client");
			c->Free();
		}
		// */
		//*
		TEST_METHOD(LocalStorageGetShouldReadData)
		{
			LocalStorage<Client> storage;
			std::string main = "main";
			Client& client = storage.Get(storage.Client(), main);
			Assert::AreEqual(main, client.Id());
			//client->Free();
		}
		// */
	};
}