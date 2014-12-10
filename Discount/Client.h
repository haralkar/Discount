#pragma once
#include <string>
#include "IData.h"

class Client : public IData
{
public:
	Client();
	virtual ~Client();

	void Free() { delete this; }

	static IData * __stdcall Create() { return new Client(); }
private:
	std::string name_;
};

