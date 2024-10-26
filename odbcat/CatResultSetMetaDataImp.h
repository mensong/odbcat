#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/ResultSetMetaData.h>

using namespace odbc;

class CatResultSetMetaDataImp
	: public CatBase
	, public CatResultSetMetaData
{
public:
	CatResultSetMetaDataImp(ResultSetMetaDataRef ref);

	// Í¨¹ý CatResultSetMetaData ¼Ì³Ð
	virtual unsigned short getColumnCount() override;

	virtual short getColumnType(unsigned short columnIndex) override;

	virtual size_t getColumnLength(unsigned short columnIndex) override;

	virtual size_t getColumnOctetLength(unsigned short columnIndex) override;

	virtual size_t getColumnDisplaySize(unsigned short columnIndex) override;

	virtual unsigned short getPrecision(unsigned short columnIndex) override;

	virtual unsigned short getScale(unsigned short columnIndex) override;

	virtual bool isAutoIncrement(unsigned short columnIndex) override;

	virtual bool isCaseSensitive(unsigned short columnIndex) override;

	virtual bool isNamed(unsigned short columnIndex) override;

	virtual bool isNullable(unsigned short columnIndex) override;

	virtual bool isReadOnly(unsigned short columnIndex) override;

	virtual bool isSearchable(unsigned short columnIndex) override;

	virtual bool isSigned(unsigned short columnIndex) override;

	virtual const char* getCatalogName(unsigned short columnIndex) override;

	virtual const char* getSchemaName(unsigned short columnIndex) override;

	virtual const char* getTableName(unsigned short columnIndex) override;

	virtual const char* getBaseTableName(unsigned short columnIndex) override;

	virtual const char* getBaseColumnName(unsigned short columnIndex) override;

	virtual const char* getColumnLabel(unsigned short columnIndex) override;

	virtual const char* getColumnName(unsigned short columnIndex) override;

	virtual const char* getColumnTypeName(unsigned short columnIndex) override;

protected:
	ResultSetMetaDataRef m_raw;

	std::string m_buffer;
};

