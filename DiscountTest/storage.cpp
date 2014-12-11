#include "stdafx.h"
#include "CppUnitTest.h"

#include "Client.h"
#include "Rebate.h"
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
			storage.Cleanup();
		}
		TEST_METHOD(LocalStorageGetShould)
		{
			LocalStorage<Client> storage;
			Client& c = storage.Get(storage.Client());
			storage.Cleanup();
		}
		TEST_METHOD(LocalStorageGetShouldKeepData)
		{
			LocalStorage<Client> storage;

			std::string main = "main";
			Client& client = storage.Get(storage.Client(), main);
			Assert::AreEqual(main, client.Id());
			
			std::string name("Name");
			client.SetName(name);

			Client& client2 = storage.Get(storage.Client(), main);
			Assert::AreEqual(name, client2.Name());
			storage.Cleanup();
		}
		TEST_METHOD(PersistencyInAllThings)
		{
			LocalStorage<Rebate> storageToCleanUp;
			{
				LocalStorage<Rebate> storage;

				Rebate& rebate = storage.Get("rebate", "tenFlat");
				rebate.SetName("Ten percent");
				rebate.SetProcent(10);
			}
			{
				LocalStorage<Rebate> storage;

				Rebate& rebate = storage.Get("rebate", "tenFlat");
				Assert::AreEqual(10, rebate.Procent());
			}
			storageToCleanUp.Cleanup();
		}
	};
}