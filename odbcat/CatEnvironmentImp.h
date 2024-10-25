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
	virtual bool configDSN(const wchar_t* attributesString, 
		const wchar_t* driver = NULL, ConfigDsnAction action = AddDSN) override;
	virtual bool configDSNByFile(const wchar_t* dsnFile, const wchar_t* DSNName, 
		const wchar_t* driver = NULL, ConfigDsnAction action = AddDSN) override;
	virtual bool isDriverInstalled(const char* driver) override;
	virtual CatDataSourceInformations* getDataSources() override;
	virtual CatDataSourceInformations* getDataSources(CatDSNType dsnType) override;
	virtual CatDriverInformations* getDrivers() override;

protected:
	EnvironmentRef m_raw;

};

