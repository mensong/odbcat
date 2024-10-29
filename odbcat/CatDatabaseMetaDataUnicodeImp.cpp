#include "pch.h"
#include "CatDatabaseMetaDataUnicodeImp.h"
#include "CatResultSetImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatDatabaseMetaDataUnicodeImp::CatDatabaseMetaDataUnicodeImp(DatabaseMetaDataUnicodeRef ref)
    : m_raw(ref)
{
}

unsigned short CatDatabaseMetaDataUnicodeImp::getMaxConnections()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getMaxConnections();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return 0;
    }
}

unsigned long CatDatabaseMetaDataUnicodeImp::getMaxStatementLength()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getMaxStatementLength();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return 0;
    }
}

bool CatDatabaseMetaDataUnicodeImp::isReadOnly()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->isReadOnly();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return false;
    }
}

bool CatDatabaseMetaDataUnicodeImp::supportsAlterTableWithAddColumn()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->supportsAlterTableWithAddColumn();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return false;
    }
}

bool CatDatabaseMetaDataUnicodeImp::supportsAlterTableWithDropColumn()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->supportsAlterTableWithDropColumn();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return false;
    }
}

CatTransactionIsolationLevel CatDatabaseMetaDataUnicodeImp::getDefaultTransactionIsolation()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return (CatTransactionIsolationLevel)m_raw->getDefaultTransactionIsolation();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return CatTransactionIsolationLevel::NONE;
    }
}

bool CatDatabaseMetaDataUnicodeImp::supportsTransactionIsolation(CatTransactionIsolationLevel level)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->supportsTransactionIsolation((TransactionIsolationLevel)level);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return false;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getColumns(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, const char16_t* columnName)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getColumns(catalogName, schemaName, tableName, columnName));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getColumnPrivileges(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, const char16_t* columnName)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getColumnPrivileges(catalogName, schemaName, tableName, columnName));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getPrimaryKeys(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getPrimaryKeys(catalogName, schemaName, tableName));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getSpecialColumns(CatRowIdentifierType identifierType, const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, CatRowIdentifierScope scope, CatColumnNullableValue nullable)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getSpecialColumns((RowIdentifierType)identifierType, catalogName, schemaName, tableName, (RowIdentifierScope)scope, (ColumnNullableValue)nullable));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getStatistics(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, CatIndexType indexType, CatStatisticsAccuracy accuracy)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getStatistics(catalogName, schemaName, tableName, (IndexType)indexType, (StatisticsAccuracy)accuracy));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getTables(const char16_t* catalogName, const char16_t* schemaName, const char16_t* tableName, const char16_t* tableType)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getTables(catalogName, schemaName, tableName, tableType));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getTypeInfo()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getTypeInfo());
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataUnicodeImp::getTypeInfo(int type)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->getTypeInfo(type));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getDataSourceName()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getDataSourceName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getDatabaseName()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getDatabaseName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getDBMSName()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getDBMSName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getDBMSVersion()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getDBMSVersion();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getDriverName()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getDriverName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getDriverVersion()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getDriverVersion();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getServerName()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getServerName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

const char16_t* CatDatabaseMetaDataUnicodeImp::getUserName()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_buffer = m_raw->getUserName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}
