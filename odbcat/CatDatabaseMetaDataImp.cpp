#include "pch.h"
#include "CatDatabaseMetaDataImp.h"
#include "CatResultSetImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatDatabaseMetaDataImp::CatDatabaseMetaDataImp(DatabaseMetaDataRef ref)
    : m_raw(ref)
{
}

unsigned short CatDatabaseMetaDataImp::getMaxConnections()
{
    g_hasError = false;
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

unsigned long CatDatabaseMetaDataImp::getMaxStatementLength()
{
    g_hasError = false;
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

bool CatDatabaseMetaDataImp::isReadOnly()
{
    g_hasError = false;
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

bool CatDatabaseMetaDataImp::supportsAlterTableWithAddColumn()
{
    g_hasError = false;
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

bool CatDatabaseMetaDataImp::supportsAlterTableWithDropColumn()
{
    g_hasError = false;
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

CatTransactionIsolationLevel CatDatabaseMetaDataImp::getDefaultTransactionIsolation()
{
    g_hasError = false;
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

bool CatDatabaseMetaDataImp::supportsTransactionIsolation(CatTransactionIsolationLevel level)
{
    g_hasError = false;
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

CatResultSet* CatDatabaseMetaDataImp::getColumns(const char* catalogName, const char* schemaName, const char* tableName, const char* columnName)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getColumns(catalogName, schemaName, tableName, columnName));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getColumnPrivileges(const char* catalogName, const char* schemaName, const char* tableName, const char* columnName)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getColumnPrivileges(catalogName, schemaName, tableName, columnName));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getPrimaryKeys(const char* catalogName, const char* schemaName, const char* tableName)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getPrimaryKeys(catalogName, schemaName, tableName));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getSpecialColumns(CatRowIdentifierType identifierType, const char* catalogName, const char* schemaName, const char* tableName, CatRowIdentifierScope scope, CatColumnNullableValue nullable)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getSpecialColumns((RowIdentifierType)identifierType, catalogName, schemaName, tableName, (RowIdentifierScope)scope, (ColumnNullableValue)nullable));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getStatistics(const char* catalogName, const char* schemaName, const char* tableName, CatIndexType indexType, CatStatisticsAccuracy accuracy)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getStatistics(catalogName, schemaName, tableName, (IndexType)indexType, (StatisticsAccuracy)accuracy));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getTables(const char* catalogName, const char* schemaName, const char* tableName, const char* tableType)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getTables(catalogName, schemaName, tableName, tableType));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getTypeInfo()
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getTypeInfo());
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatResultSet* CatDatabaseMetaDataImp::getTypeInfo(int type)
{
    g_hasError = false;
    try
    {
        return new CatResultSetImp(m_raw->getTypeInfo(type));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getDataSourceName()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getDataSourceName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getDatabaseName()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getDatabaseName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getDBMSName()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getDBMSName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getDBMSVersion()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getDBMSVersion();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getDriverName()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getDriverName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getDriverVersion()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getDriverVersion();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getServerName()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getServerName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

const char* CatDatabaseMetaDataImp::getUserName()
{
    g_hasError = false;
    try
    {
        m_buffer = m_raw->getUserName();
        return m_buffer.c_str();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}
