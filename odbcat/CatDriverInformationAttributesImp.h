#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/Environment.h>
#include <vector>

using namespace odbc;

class CatDriverInformationAttributesImp
	: public CatDriverInformationAttributes
	, public CatBase
{
public:
	CatDriverInformationAttributesImp(std::vector<DriverInformation::Attribute>& ref);

	// Í¨¹ý CatDriverInformationAttributes ¼Ì³Ð
	virtual int count() override;

	virtual const char* name(int idx) override;

	virtual const char* value(int idx) override;

protected:
	std::vector<DriverInformation::Attribute> m_raw;
};

