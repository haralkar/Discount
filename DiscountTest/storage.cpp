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
			LocalStorage storage;
			Assert::IsTrue(true);
		}
		TEST_METHOD(LocalStorageGetShould)
		{
			LocalStorage storage;
			Client* c = (Client*)storage.Get("client");
			Assert::IsNotNull(c);
			c->Free();
		}
	};
}