#include "pch.h"
#include "CatResultSetMetaDataImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatResultSetMetaDataImp::CatResultSetMetaDataImp(ResultSetMetaDataRef ref)
    : m_raw(ref)
{
}

unsigned short CatResultSetMetaDataImp::getColumnCount()
{
    g_hasError = false; g_errorMsg.clear();
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

CatColumnType CatResultSetMetaDataImp::getColumnType(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return (CatColumnType)m_raw->getColumnType(columnIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return CatColumnType::CT_UNKNOWN_TYPE;
    }
}

size_t CatResultSetMetaDataImp::getColumnLength(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

size_t CatResultSetMetaDataImp::getColumnOctetLength(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

size_t CatResultSetMetaDataImp::getColumnDisplaySize(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

unsigned short CatResultSetMetaDataImp::getPrecision(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

unsigned short CatResultSetMetaDataImp::getScale(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isAutoIncrement(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isCaseSensitive(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isNamed(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isNullable(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isReadOnly(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isSearchable(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

bool CatResultSetMetaDataImp::isSigned(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getCatalogName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getSchemaName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getTableName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getBaseTableName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getBaseColumnName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getColumnLabel(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getColumnName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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

const char* CatResultSetMetaDataImp::getColumnTypeName(unsigned short columnIndex)
{
    g_hasError = false; g_errorMsg.clear();
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
