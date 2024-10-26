#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/Statement.h>

using namespace odbc;

class CatStatementImp
	: public CatBase
	, public CatStatement
{
public:
	CatStatementImp(StatementRef ref);

	// Í¨¹ý CatStatement ¼Ì³Ð
	virtual unsigned long getMaxRows() override;

	virtual void setMaxRows(unsigned long maxRows) override;

	virtual unsigned long getQueryTimeout() override;

	virtual void setQueryTimeout(unsigned long seconds) override;

	virtual bool execute(const char* sql) override;

	virtual bool execute(const char16_t* sql) override;

	virtual CatResultSet* executeQuery(const char* sql) override;

	virtual CatResultSet* executeQuery(const char16_t* sql) override;

protected:
	StatementRef m_raw;
};

