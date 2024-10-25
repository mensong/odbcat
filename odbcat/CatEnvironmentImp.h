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
	virtual bool createDSN(const wchar_t* attributesString, const wchar_t* driver = NULL, bool sysDsn = false) override;
	virtual bool createDSNByFile(const wchar_t* dsnFile, const wchar_t* DSNName, const wchar_t* driver = NULL, bool sysDsn = false) override;

protected:
	EnvironmentRef m_raw;

};

