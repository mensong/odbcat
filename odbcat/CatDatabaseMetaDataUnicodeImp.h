#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/DatabaseMetaDataUnicode.h>

using namespace odbc;

class CatDatabaseMetaDataUnicodeImp
	: public CatDatabaseMetaDataUnicode
	, public CatBase
{
public:
	CatDatabaseMetaDataUnicodeImp(DatabaseMetaDataUnicodeRef ref);

	// Í¨¹ý CatDatabaseMetaDataUnicode ¼Ì³Ð
	virtual unsigned short getMaxConnections() override;

	virtual unsigned long getMaxStatementLength() override;

	virtual bool isReadOnly() override;

	virtual bool supportsAlterTableWithAddColumn() override;

	virtual bool supportsAlterTableWithDropColumn() override;

	virtual CatTransactionIsolationLevel getDefaultTransactionIsolation() override;

	virtual bool supportsTransactionIsolation(CatTransactionIsolationLevel level) override;

	virtual CatResultSet* getColumns(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, const char16_t* columnName) override;

	virtual CatResultSet* getColumnPrivileges(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, const char16_t* columnName) override;

	virtual CatResultSet* getPrimaryKeys(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName) override;

	virtual CatResultSet* getSpecialColumns(CatRowIdentifierType identifierType, const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, CatRowIdentifierScope scope, CatColumnNullableValue nullable) override;

	virtual CatResultSet* getStatistics(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, CatIndexType indexType, CatStatisticsAccuracy accuracy) override;

	virtual CatResultSet* getTables(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, const char16_t* tableType) override;

	virtual CatResultSet* getTypeInfo() override;

	virtual CatResultSet* getTypeInfo(int type) override;

	virtual const char16_t* getDataSourceName() override;

	virtual const char16_t* getDatabaseName() override;

	virtual const char16_t* getDBMSName() override;

	virtual const char16_t* getDBMSVersion() override;

	virtual const char16_t* getDriverName() override;

	virtual const char16_t* getDriverVersion() override;

	virtual const char16_t* getServerName() override;

	virtual const char16_t* getUserName() override;

protected:
	DatabaseMetaDataUnicodeRef m_raw;

	std::u16string m_buffer;
};

