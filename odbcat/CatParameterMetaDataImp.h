#pragma once
#include "odbcat.h"
#include <odbc/Forwards.h>
#include <odbc/ParameterMetaData.h>

using namespace odbc;

class CatParameterMetaDataImp
	: public CatParameterMetaData
	, public CatBase
{
public:
	CatParameterMetaDataImp(ParameterMetaDataRef ref);

	// Í¨¹ý CatParameterMetaData ¼Ì³Ð
	virtual unsigned short getParameterCount() override;

	virtual short getParameterType(unsigned short paramIndex) override;

	virtual size_t getParameterSize(unsigned short paramIndex) override;

	virtual unsigned short getPrecision(unsigned short paramIndex) override;

	virtual unsigned short getScale(unsigned short paramIndex) override;

	virtual bool isNullable(unsigned short paramIndex) override;

protected:
	ParameterMetaDataRef m_raw;
};

