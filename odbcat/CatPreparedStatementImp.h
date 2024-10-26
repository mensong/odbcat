#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/PreparedStatement.h>

using namespace odbc;

class CatPreparedStatementImp
	: public CatBase
	, public CatPreparedStatement
{
public:
	CatPreparedStatementImp(PreparedStatementRef ref);

	// Í¨¹ý CatPreparedStatement ¼Ì³Ð
	virtual unsigned long getMaxRows() override;

	virtual void setMaxRows(unsigned long maxRows) override;

	virtual unsigned long getQueryTimeout() override;

	virtual void setQueryTimeout(unsigned long seconds) override;

	virtual CatParameterMetaData* getParameterMetaData() override;

	virtual void setBoolean(unsigned short paramIndex, bool value) override;

	virtual void setByte(unsigned short paramIndex, INT8 value) override;

	virtual void setUByte(unsigned short paramIndex, UINT8 value) override;

	virtual void setShort(unsigned short paramIndex, INT16 value) override;

	virtual void setUShort(unsigned short paramIndex, UINT16 value) override;

	virtual void setInt(unsigned short paramIndex, int value) override;

	virtual void setUInt(unsigned short paramIndex, UINT value) override;

	virtual void setLong(unsigned short paramIndex, long long value) override;

	virtual void setULong(unsigned short paramIndex, unsigned long long value) override;

	virtual void setFloat(unsigned short paramIndex, float value) override;

	virtual void setDouble(unsigned short paramIndex, double value) override;

	virtual void setCString(unsigned short paramIndex, const char* s) override;

	virtual void setCString(unsigned short paramIndex, const char* s, size_t len) override;

	virtual void setNCString(unsigned short paramIndex, const char16_t* s) override;

	virtual void setNCString(unsigned short paramIndex, const char16_t* s, size_t len) override;

	virtual void setBytes(unsigned short paramIndex, const void* data, size_t size) override;

	virtual void setDate(unsigned short paramIndex, int year, int month, int day) override;

	virtual void setTime(unsigned short paramIndex, int hour, int minute, int second) override;

	virtual void setTimestamp(unsigned short paramIndex, 
		int year, int month, int day,
		int hour, int minute, int second, int milliseconds) override;

	virtual void clearParameters() override;

	virtual CatResultSetMetaData* getMetaData() override;

	virtual CatResultSetMetaDataUnicode* getMetaDataUnicode() override;

	virtual CatResultSet* executeQuery() override;

	virtual size_t executeUpdate() override;

	virtual bool addBatch() override;

	virtual bool executeBatch() override;

	virtual void clearBatch() override;

	virtual size_t getBatchDataSize() override;

protected:
	PreparedStatementRef m_raw;
};

