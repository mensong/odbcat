#include "pch.h"
#include "CatResultSetMetaDataUnicodeImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatResultSetMetaDataUnicodeImp::CatResultSetMetaDataUnicodeImp(ResultSetMetaDataUnicodeRef ref)
    : m_raw(ref)
{
}

unsigned short CatResultSetMetaDataUnicodeImp::getColumnCount()
{
    g_hasError = false;
    try
    {
        return m_raw->getColumnCount();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

short CatResultSetMetaDataUnicodeImp::getColumnType(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getColumnType(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

size_t CatResultSetMetaDataUnicodeImp::getColumnLength(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getColumnLength(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

size_t CatResultSetMetaDataUnicodeImp::getColumnOctetLength(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getColumnOctetLength(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

size_t CatResultSetMetaDataUnicodeImp::getColumnDisplaySize(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getColumnDisplaySize(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned short CatResultSetMetaDataUnicodeImp::getPrecision(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getPrecision(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned short CatResultSetMetaDataUnicodeImp::getScale(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getScale(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

bool CatResultSetMetaDataUnicodeImp::isAutoIncrement(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isAutoIncrement(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetMetaDataUnicodeImp::isCaseSensitive(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isCaseSensitive(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetMetaDataUnicodeImp::isNamed(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isNamed(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetMetaDataUnicodeImp::isNullable(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isNullable(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetMetaDataUnicodeImp::isReadOnly(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isReadOnly(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetMetaDataUnicodeImp::isSearchable(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isSearchable(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatResultSetMetaDataUnicodeImp::isSigned(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isSigned(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getCatalogName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getCatalogName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getSchemaName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getSchemaName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getTableName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getTableName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getBaseTableName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getBaseTableName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getBaseColumnName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getBaseColumnName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getColumnLabel(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getColumnLabel(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getColumnName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getColumnName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatResultSetMetaDataUnicodeImp::getColumnTypeName(unsigned short columnIndex)
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getColumnTypeName(columnIndex + 1);
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}
