#include "pch.h"
#include "CatPreparedStatementImp.h"
#include "CatParameterMetaDataImp.h"
#include "CatResultSetMetaDataImp.h"
#include "CatResultSetMetaDataUnicodeImp.h"
#include "CatResultSetImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatPreparedStatementImp::CatPreparedStatementImp(PreparedStatementRef ref)
    : m_raw(ref)
{
}

unsigned long CatPreparedStatementImp::getMaxRows()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getMaxRows();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

void CatPreparedStatementImp::setMaxRows(unsigned long maxRows)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setMaxRows(maxRows);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

unsigned long CatPreparedStatementImp::getQueryTimeout()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getQueryTimeout();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

void CatPreparedStatementImp::setQueryTimeout(unsigned long seconds)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setQueryTimeout(seconds);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

CatParameterMetaData* CatPreparedStatementImp::getParameterMetaData()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatParameterMetaDataImp(m_raw->getParameterMetaData());
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

void CatPreparedStatementImp::setBoolean(unsigned short paramIndex, bool value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setBoolean(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setByte(unsigned short paramIndex, INT8 value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setByte(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setUByte(unsigned short paramIndex, UINT8 value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setUByte(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setShort(unsigned short paramIndex, INT16 value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setShort(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setUShort(unsigned short paramIndex, UINT16 value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setUShort(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setInt(unsigned short paramIndex, int value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setInt(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setUInt(unsigned short paramIndex, UINT value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setUInt(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setLong(unsigned short paramIndex, long long value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setLong(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setULong(unsigned short paramIndex, unsigned long long value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setULong(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setFloat(unsigned short paramIndex, float value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setFloat(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setDouble(unsigned short paramIndex, double value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setDouble(paramIndex + 1, value);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setCString(unsigned short paramIndex, const char* s)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setCString(paramIndex + 1, s);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setCString(unsigned short paramIndex, const char* s, size_t len)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setCString(paramIndex + 1, s, len);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setNCString(unsigned short paramIndex, const char16_t* s)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setNCString(paramIndex + 1, s);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setNCString(unsigned short paramIndex, const char16_t* s, size_t len)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setNCString(paramIndex + 1, s, len);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setBytes(unsigned short paramIndex, const void* data, size_t size)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setBytes(paramIndex + 1, data, size);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setDate(unsigned short paramIndex, int year, int month, int day)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setDate(paramIndex + 1, odbc::date(year, month, day));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setTime(unsigned short paramIndex, int hour, int minute, int second)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setTime(paramIndex + 1, odbc::time(hour, minute, second));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::setTimestamp(unsigned short paramIndex, 
    int year, int month, int day,
    int hour, int minute, int second, int milliseconds)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setTimestamp(paramIndex + 1, odbc::timestamp(
            year, month, day, hour, minute, second, milliseconds));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

void CatPreparedStatementImp::clearParameters()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->clearParameters();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

CatResultSetMetaData* CatPreparedStatementImp::getMetaData()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetMetaDataImp(m_raw->getMetaData());
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSetMetaDataUnicode* CatPreparedStatementImp::getMetaDataUnicode()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetMetaDataUnicodeImp(m_raw->getMetaDataUnicode());
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatPreparedStatementImp::executeQuery()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->executeQuery());
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

size_t CatPreparedStatementImp::executeUpdate()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->executeUpdate();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

bool CatPreparedStatementImp::addBatch()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->addBatch();
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatPreparedStatementImp::executeBatch()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->executeBatch();
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

void CatPreparedStatementImp::clearBatch()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->clearBatch();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

size_t CatPreparedStatementImp::getBatchDataSize()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getBatchDataSize();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}
