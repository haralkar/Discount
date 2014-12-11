#include "stdafx.h"
#include "Product.h"


Product::Product()
{
}


Product::~Product()
{
}

std::string Product::Id() 
{ 
	return id_; 
}
void Product::SetId(std::string id) 
{ 
	id_ = id; 
}

std::string Product::Name() 
{ 
	return name_; 
}
void Product::SetName(std::string name) 
{ 
	name_ = name; 
}

int Product::Price() 
{ 
	return price_; 
}
void Product::SetPrice(int price) 
{ 
	price_ = price; 
}

IData* __stdcall Product::Create() 
{ 
	return new Product(); 
}
CreateDataFn Product::Creator() const 
{ 
	return Create; 
}

std::string Product::DataTitle() const 
{
	return "product"; 
}
