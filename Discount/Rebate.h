#pragma once
#include "IData.h"
class Rebate : public IData
{
public:
	Rebate();
	virtual ~Rebate();
	void Free();

	static IData* __stdcall Create();
	virtual CreateDataFn Creator() const;
	virtual std::string DataTitle() const final;


	virtual std::string Id();
	virtual void SetId(std::string id);

	virtual std::string Name();
	virtual void SetName(std::string name);

	virtual int Percent();
	virtual void SetPercent(int p);

	virtual std::string Client();
	virtual void SetClient(std::string );

	virtual std::string Product();
	virtual void SetProduct(std::string);


private:
	std::string id_;
	std::string name_;
	std::string client_;
	std::string product_;
	int perCent_;
};

