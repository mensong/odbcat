#include "pch.h"
#include "CatConnectionImp.h"
#include "CatStatementImp.h"
#include "CatPreparedStatementImp.h"
#include "CatDatabaseMetaDataImp.h"
#include "CatDatabaseMetaDataUnicodeImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatConnectionImp::CatConnectionImp(ConnectionRef ref)
    : m_raw(ref)
{
}

CatConnectionImp::~CatConnectionImp()
{

}

bool CatConnectionImp::connectByDSNName(const char* dsn, const char* user/* = NULL*/, const char* password/* = NULL*/)
{
	g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->connect(dsn, user, password);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
    
    return m_raw->connected();
}

bool CatConnectionImp::connect(const char* connString)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->connect(connString);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
    
    return m_raw->connected();
}

void CatConnectionImp::disconnect()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->disconnect();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

bool CatConnectionImp::connected()
{
    return m_raw->connected();
}

bool CatConnectionImp::isValid()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->isValid();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return false;
    }
}

unsigned long CatConnectionImp::getConnectionTimeout()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getConnectionTimeout();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return 0;
    }
}

void CatConnectionImp::setConnectionTimeout(unsigned long seconds)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setConnectionTimeout(seconds);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

unsigned long CatConnectionImp::getLoginTimeout()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getLoginTimeout();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return 0;
    }
}

void CatConnectionImp::setLoginTimeout(unsigned long seconds)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setLoginTimeout(seconds);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::setAttribute(int attr, int value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setAttribute(attr, value);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::setAttribute(int attr, unsigned int value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setAttribute(attr, value);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::setAttribute(int attr, const char* value)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setAttribute(attr, value);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::setAttribute(int attr, const char* value, size_t length)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setAttribute(attr, value, length);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::setAttribute(int attr, const void* value, size_t size)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setAttribute(attr, value, size);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

bool CatConnectionImp::getAutoCommit()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->getAutoCommit();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return false;
    }
}

void CatConnectionImp::setAutoCommit(bool autoCommit)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setAutoCommit(autoCommit);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::commit()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->commit();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

void CatConnectionImp::rollback()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->rollback();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

bool CatConnectionImp::isReadOnly()
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

void CatConnectionImp::setReadOnly(bool readOnly)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setReadOnly(readOnly);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

CatTransactionIsolationLevel CatConnectionImp::getTransactionIsolation()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return (CatTransactionIsolationLevel)m_raw->getTransactionIsolation();
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return CatTransactionIsolationLevel::NONE;
    }
}

void CatConnectionImp::setTransactionIsolation(CatTransactionIsolationLevel level)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->setTransactionIsolation((TransactionIsolationLevel)level);
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
    }
}

CatStatement* CatConnectionImp::createStatement()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatStatementImp(m_raw->createStatement());
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatPreparedStatement* CatConnectionImp::prepareStatement(const char* sql)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatPreparedStatementImp(m_raw->prepareStatement(sql));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatPreparedStatement* CatConnectionImp::prepareStatement(const char16_t* sql)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatPreparedStatementImp(m_raw->prepareStatement(sql));
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatDatabaseMetaData* CatConnectionImp::getDatabaseMetaData()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatDatabaseMetaDataImp(m_raw->getDatabaseMetaData());
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}

CatDatabaseMetaDataUnicode* CatConnectionImp::getDatabaseMetaDataUnicode()
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatDatabaseMetaDataUnicodeImp(m_raw->getDatabaseMetaDataUnicode());
    }
    catch (const std::exception& ex)
    {
        g_errorMsg = ex.what();
        g_hasError = true;
        return NULL;
    }
}
