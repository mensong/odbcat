#include "pch.h"
#include "CatEnvironmentImp.h"
#include "CatConnectionImp.h"

using namespace odbc;

extern bool g_hasError;
extern std::string g_errorMsg;

CatEnvironmentImp::CatEnvironmentImp()
{
    g_hasError = false;
    try
    {
        m_raw = Environment::create();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
    }
}

CatConnection* CatEnvironmentImp::createConnection()
{
    g_hasError = false;
    try
    {
        ConnectionRef conn = m_raw->createConnection();
        return new CatConnectionImp(conn);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return NULL;
    }
}
