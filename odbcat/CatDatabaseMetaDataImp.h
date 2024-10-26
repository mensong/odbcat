#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/DatabaseMetaData.h>

using namespace odbc;

class CatDatabaseMetaDataImp
	: public CatBase
	, public CatDatabaseMetaData
{
public:
	CatDatabaseMetaDataImp(DatabaseMetaDataRef ref);

	// Í¨¹ý CatDatabaseMetaData ¼Ì³Ð
	virtual unsigned short getMaxConnections() override;
	virtual unsigned long getMaxStatementLength() override;
	virtual bool isReadOnly() override;
	virtual bool supportsAlterTableWithAddColumn() override;
	virtual bool supportsAlterTableWithDropColumn() override;
	virtual CatTransactionIsolationLevel getDefaultTransactionIsolation() override;
	virtual bool supportsTransactionIsolation(CatTransactionIsolationLevel level) override;
	virtual CatResultSet* getColumns(const char* catalogName, const char* schemaName, const char* tableName, const char* columnName) override;
	virtual CatResultSet* getColumnPrivileges(const char* catalogName, const char* schemaName, const char* tableName, const char* columnName) override;
	virtual CatResultSet* getPrimaryKeys(const char* catalogName, const char* schemaName, const char* tableName) override;
	virtual CatResultSet* getSpecialColumns(CatRowIdentifierType identifierType, const char* catalogName, const char* schemaName, const char* tableName, CatRowIdentifierScope scope, CatColumnNullableValue nullable) override;
	virtual CatResultSet* getStatistics(const char* catalogName, const char* schemaName, const char* tableName, CatIndexType indexType, CatStatisticsAccuracy accuracy) override;
	virtual CatResultSet* getTables(const char* catalogName, const char* schemaName, const char* tableName, const char* tableType) override;
	virtual CatResultSet* getTypeInfo() override;
	virtual CatResultSet* getTypeInfo(int type) override;
	virtual const char* getDataSourceName() override;
	virtual const char* getDatabaseName() override;
	virtual const char* getDBMSName() override;
	virtual const char* getDBMSVersion() override;
	virtual const char* getDriverName() override;
	virtual const char* getDriverVersion() override;
	virtual const char* getServerName() override;
	virtual const char* getUserName() override;

protected:
	DatabaseMetaDataRef m_raw;

	std::string m_buffer;
};

