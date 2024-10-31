#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/ResultSet.h>

using namespace odbc;

class CatResultSetImp
	: public CatBase
	, public CatResultSet
{
public:
	CatResultSetImp(ResultSetRef ref);

public:
	// Í¨¹ý CatResultSet ¼Ì³Ð
	virtual bool next() override;

	virtual void close() override;

	virtual CatResultSetMetaData* getMetaData() override;

	virtual CatResultSetMetaDataUnicode* getMetaDataUnicode() override;

	virtual bool getBoolean(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual std::int8_t getByte(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual std::uint8_t getUByte(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual short getShort(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual unsigned short getUShort(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual int getInt(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual unsigned int getUInt(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual long long getLong(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual unsigned long long getULong(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual float getFloat(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual double getDouble(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual bool getDate(unsigned short columnIndex, int* year, int* month, int* day, bool* outIsNull = NULL) override;

	virtual bool getTime(unsigned short columnIndex, int* hour, int* minute, int* second, bool* outIsNull = NULL) override;

	virtual bool getTimestamp(unsigned short columnIndex,
		int* year, int* month, int* day, 
		int* hour, int* minute, int* second, int* milliseconds, 
		bool* outIsNull = NULL) override;

	virtual size_t getBinaryLength(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual void getBinaryData(unsigned short columnIndex, void* outData, size_t size) override;

	virtual size_t getStringLength(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual void getStringData(unsigned short columnIndex, void* outData, size_t size) override;

	virtual size_t getNStringLength(unsigned short columnIndex, bool* outIsNull = NULL) override;

	virtual void getNStringData(unsigned short columnIndex, void* outData, size_t size) override;

protected:
	ResultSetRef m_raw;
};

