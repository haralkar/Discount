#pragma once
#include <string>
#include "IData.h"

class Client : public IData
{
public:
	Client();
	virtual ~Client();

	void Free() { delete this; }

	virtual std::string Id() { return name_; }
	virtual void SetId(std::string id) { name_ = id; }

	static IData * __stdcall Create() { return new Client(); }
private:
	std::string name_;
};

