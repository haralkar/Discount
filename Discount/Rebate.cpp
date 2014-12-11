#include "stdafx.h"
#include "Rebate.h"


Rebate::Rebate()
{
}


Rebate::~Rebate()
{
}

IData* __stdcall Rebate::Create() 
{ 
	return new Rebate(); 
}
CreateDataFn Rebate::Creator() const
{
	return Create; 
}

std::string Rebate::DataTitle() const 
{ 
	return "rebate"; 
}

void Rebate::Free() 
{ 
	delete this; 
}

std::string Rebate::Id() 
{ 
	return id_; 
}
void Rebate::SetId(std::string id) 
{ 
	id_ = id; 
}

std::string Rebate::Name() 
{ 
	return name_; 
}
void Rebate::SetName(std::string name) 
{ 
	name_ = name; 
}

int Rebate::Percent() 
{
	return perCent_;
}
void Rebate::SetPercent(int p)
{
	perCent_ = p;
}

std::string Rebate::Client()
{
	return client_;
}
void Rebate::SetClient(std::string client)
{
	client_ = client;
}
std::string Rebate::Product()
{
	return product_;
}
void Rebate::SetProduct(std::string product)
{
	product_ = product;
}
