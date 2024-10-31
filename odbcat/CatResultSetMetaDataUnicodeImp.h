#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/ResultSetMetaDataUnicode.h>

using namespace odbc;

class CatResultSetMetaDataUnicodeImp
	: public CatBase
	, public CatResultSetMetaDataUnicode
{
public:
	CatResultSetMetaDataUnicodeImp(ResultSetMetaDataUnicodeRef ref);

	// Í¨¹ý CatResultSetMetaDataUnicode ¼Ì³Ð
	virtual unsigned short getColumnCount() override;

	virtual CatColumnType getColumnType(unsigned short columnIndex) override;

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

	virtual const char16_t* getCatalogName(unsigned short columnIndex) override;

	virtual const char16_t* getSchemaName(unsigned short columnIndex) override;

	virtual const char16_t* getTableName(unsigned short columnIndex) override;

	virtual const char16_t* getBaseTableName(unsigned short columnIndex) override;

	virtual const char16_t* getBaseColumnName(unsigned short columnIndex) override;

	virtual const char16_t* getColumnLabel(unsigned short columnIndex) override;

	virtual const char16_t* getColumnName(unsigned short columnIndex) override;

	virtual const char16_t* getColumnTypeName(unsigned short columnIndex) override;

protected:
	ResultSetMetaDataUnicodeRef m_raw;

	std::u16string m_buffer;
};

