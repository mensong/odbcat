#include "pch.h"
#include "CatStatementImp.h"
#include "CatResultSetImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatStatementImp::CatStatementImp(StatementRef ref)
    : m_raw(ref)
{
}

unsigned long CatStatementImp::getMaxRows()
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

void CatStatementImp::setMaxRows(unsigned long maxRows)
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

unsigned long CatStatementImp::getQueryTimeout()
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

void CatStatementImp::setQueryTimeout(unsigned long seconds)
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

bool CatStatementImp::execute(const char* sql)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->execute(sql);
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

bool CatStatementImp::execute(const char16_t* sql)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        m_raw->execute(sql);
        return true;
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

CatResultSet* CatStatementImp::executeQuery(const char* sql)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->executeQuery(sql));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}

CatResultSet* CatStatementImp::executeQuery(const char16_t* sql)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return new CatResultSetImp(m_raw->executeQuery(sql));
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}
