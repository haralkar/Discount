#pragma once
#include <string>

class IData;
typedef IData* (__stdcall *CreateDataFn)(void);

class IData
{
public:
	virtual void Free() = 0;

	virtual std::string Id() = 0;
	virtual void SetId(std::string id) = 0;
	
	virtual CreateDataFn Creator() const  = 0;
	virtual std::string DataTitle() const = 0;

};

