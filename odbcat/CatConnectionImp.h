#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/Connection.h>

using namespace odbc;

class CatConnectionImp
	: public CatConnection
	, public CatBase
{
public:
	CatConnectionImp(ConnectionRef ref);
	~CatConnectionImp();

public:
	// Í¨¹ý CatConnection ¼Ì³Ð
	virtual bool connectByDSNName(const char* dsn, const char* user = NULL, const char* password = NULL) override;
	virtual bool connect(const char* connString) override;
	virtual void disconnect() override;
	virtual bool connected() override;
	virtual bool isValid() override;
	virtual unsigned long getConnectionTimeout() override;
	virtual void setConnectionTimeout(unsigned long seconds) override;
	virtual unsigned long getLoginTimeout() override;
	virtual void setLoginTimeout(unsigned long seconds) override;
	virtual void setAttribute(int attr, int value) override;
	virtual void setAttribute(int attr, unsigned int value) override;
	virtual void setAttribute(int attr, const char* value) override;
	virtual void setAttribute(int attr, const char* value, size_t length) override;
	virtual void setAttribute(int attr, const void* value, size_t size) override;
	virtual bool getAutoCommit() override;
	virtual void setAutoCommit(bool autoCommit) override;
	virtual void commit() override;
	virtual void rollback() override;
	virtual bool isReadOnly() override;
	virtual void setReadOnly(bool readOnly) override;
	virtual CatTransactionIsolationLevel getTransactionIsolation() override;
	virtual void setTransactionIsolation(CatTransactionIsolationLevel level) override;
	virtual CatStatement* createStatement() override;
	virtual CatPreparedStatement* prepareStatement(const char* sql) override;
	virtual CatPreparedStatement* prepareStatement(const char16_t* sql) override;
	virtual CatDatabaseMetaData* getDatabaseMetaData() override;
	virtual CatDatabaseMetaDataUnicode* getDatabaseMetaDataUnicode() override;

protected:
	ConnectionRef m_raw;
};

