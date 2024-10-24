#include "pch.h"
#include "CatResultSetImp.h"
#include "CatResultSetMetaDataImp.h"
#include "CatResultSetMetaDataUnicodeImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatResultSetImp::CatResultSetImp(ResultSetRef ref)
    : m_raw(ref)
{
}

bool CatResultSetImp::next()
{
    g_hasError = false;
    try
    {
        return m_raw->next();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

void CatResultSetImp::close()
{
    g_hasError = false;
    try
    {
        m_raw->close();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

CatResultSetMetaData* CatResultSetImp::getMetaData()
{
    g_hasError = false;
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

CatResultSetMetaDataUnicode* CatResultSetImp::getMetaDataUnicode()
{
    g_hasError = false;
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

bool CatResultSetImp::getBoolean(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getBoolean(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

std::int8_t CatResultSetImp::getByte(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getByte(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

std::uint8_t CatResultSetImp::getUByte(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getUByte(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

short CatResultSetImp::getShort(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getShort(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned short CatResultSetImp::getUShort(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getUShort(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

int CatResultSetImp::getInt(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getInt(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned int CatResultSetImp::getUInt(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getUInt(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

long long CatResultSetImp::getLong(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getLong(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned long long CatResultSetImp::getULong(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getULong(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

float CatResultSetImp::getFloat(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getFloat(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

double CatResultSetImp::getDouble(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return *(m_raw->getDouble(columnIndex + 1));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

bool CatResultSetImp::getDate(unsigned short columnIndex, int* year, int* month, int* day)
{
    g_hasError = false;
    try
    {
        Date date = m_raw->getDate(columnIndex + 1);
        if (date.isNull())
            return false;
        *year = date->year();
        *month = date->month();
        *day = date->day();
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetImp::getTime(unsigned short columnIndex, int* hour, int* minute, int* second)
{
    g_hasError = false;
    try
    {
        Time time = m_raw->getTime(columnIndex + 1);
        if (time.isNull())
            return false;
        *hour = time->hour();
        *minute = time->minute();
        *second = time->second();
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetImp::getTimestamp(unsigned short columnIndex,
    int* year, int* month, int* day,
    int* hour, int* minute, int* second, int* milliseconds)
{
    g_hasError = false;
    try
    {
        Timestamp ts = m_raw->getTimestamp(columnIndex + 1);
        if (ts.isNull())
            return false;
        *year = ts->year();
        *month = ts->month();
        *day = ts->day();
        *hour = ts->hour();
        *minute = ts->minute();
        *second = ts->second();
        *milliseconds = ts->milliseconds();
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

size_t CatResultSetImp::getBinaryLength(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getBinaryLength(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

void CatResultSetImp::getBinaryData(unsigned short columnIndex, void* outData, size_t size)
{
    g_hasError = false;
    try
    {
        m_raw->getBinaryData(columnIndex + 1, outData, size);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

size_t CatResultSetImp::getStringLength(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getStringLength(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

void CatResultSetImp::getStringData(unsigned short columnIndex, void* outData, size_t size)
{
    g_hasError = false;
    try
    {
        m_raw->getStringData(columnIndex + 1, outData, size);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

size_t CatResultSetImp::getNStringLength(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getNStringLength(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

void CatResultSetImp::getNStringData(unsigned short columnIndex, void* outData, size_t size)
{
    g_hasError = false;
    try
    {
        m_raw->getNStringData(columnIndex + 1, outData, size);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}
