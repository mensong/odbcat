#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/Environment.h>

using namespace odbc;

class CatEnvironmentImp
	: public CatEnvironment
	, public CatBase
{
public:
	CatEnvironmentImp();

public:
	// Í¨¹ý CatEnvironment ¼Ì³Ð
	virtual CatConnection* createConnection() override;

protected:
	EnvironmentRef m_raw;
};

