#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/Environment.h>
#include <vector>

using namespace odbc;

class CatDriverInformationsImp
	: public CatDriverInformations
	, public CatBase
{
public:
	CatDriverInformationsImp(std::vector<DriverInformation>& ref);

	// Í¨¹ý CatDriverInformations ¼Ì³Ð
	virtual int count() override;

	virtual const char* description(int idx) override;

	virtual CatDriverInformationAttributes* attributes(int idx) override;

protected:
	std::vector<DriverInformation> m_raw;
};

