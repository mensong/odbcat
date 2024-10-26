#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/Environment.h>
#include <vector>

using namespace odbc;

class CatDataSourceInformationsImp
	: public CatBase
	, public CatDataSourceInformations
{
public:
	CatDataSourceInformationsImp(std::vector<DataSourceInformation>& ref);

	virtual int count() override;
	virtual const char* name(int idx) override;
	virtual const char* description(int idx) override;

protected:
	std::vector<DataSourceInformation> m_raw;
};

