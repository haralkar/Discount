#include "stdafx.h"
#include "CppUnitTest.h"

#include "Client.h"
#include "Rebate.h"
#include "Product.h"

#include "LocalStorage.h"
#include "DataFactory.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiscountTest
{
	TEST_CLASS(DiscountCalc)
	{
	public:

		LocalStorage<Client> clientStorage;
		LocalStorage<Product> productStorage;
		LocalStorage<Rebate> rebateStorage;
		
		TEST_METHOD_INITIALIZE(Init)
		{
			/*Rebate& rebate = rebateStorage.Get("rebate", "tenFlat");
			rebate.SetName("Ten percent");
			rebate.SetProcent(10);
			*/

		}
		TEST_METHOD_CLEANUP(Cleanup)
		{
			/*clientStorage.Cleanup();
			productStorage.Cleanup();
			rebateStorage.Cleanup();
			*/

		}
		TEST_METHOD(PersistencyInAllThings)
		{
		}
	};
}