#pragma once
class IData
{
public:
	virtual void Free() = 0;

	virtual std::string Id() = 0;
	virtual void SetId(std::string id) = 0;
};

