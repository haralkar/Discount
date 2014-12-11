#pragma once
#include <string>
#include "IData.h"

class Client : public IData
{
public:
	Client();
	virtual ~Client();

	void Free() { delete this; }

	virtual std::string Id() const { return id_; }
	virtual void SetId(std::string id) { id_ = id; }

	virtual std::string Name() { return name_; }
	virtual void SetName(std::string name) { name_ = name; }


	static IData* __stdcall Create() { return new Client(); }
	virtual CreateDataFn Creator() const { return Create; }

	virtual std::string DataTitle() const final { return "client"; }

private:
	std::string id_;
	std::string name_;
};

