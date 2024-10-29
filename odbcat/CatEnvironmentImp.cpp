#include "pch.h"
#include "CatEnvironmentImp.h"
#include "CatConnectionImp.h"
#include <odbcinst.h>
#include <algorithm>
#include "CatDataSourceInformationsImp.h"
#include "CatDriverInformationsImp.h"
#pragma comment(lib, "legacy_stdio_definitions.lib")

using namespace odbc;

extern bool g_hasError;
extern std::string g_errorMsg;

CatEnvironmentImp::CatEnvironmentImp()
{
    g_hasError = false; g_errorMsg.clear();
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
    g_hasError = false; g_errorMsg.clear();
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

bool CatEnvironmentImp::configDSN(const wchar_t* attributesString, 
    const wchar_t* driver/* = NULL*/, ConfigDsnAction action/* = AddDSN*/)
{
    g_hasError = false; g_errorMsg.clear();

    std::wstring sDriver;
    if (driver)
    {
        sDriver = driver;
    }
    else
    {
        const wchar_t* p = attributesString;
        while (*p)
        {
            const wchar_t* kvstr = p;
            std::wstring kv = kvstr;
            size_t idx = kv.find('=');
            std::wstring k = kv.substr(0, idx);
            std::transform(k.begin(), k.end(), k.begin(), ::towupper);
            if (k == L"DRIVER")
            {
                sDriver = kv.substr(idx + 1);
                break;
            }
            p += wcslen(p) + 1;
        }
    }

    WORD flag = ODBC_ADD_DSN;
    switch (action)
    {
    case CatEnvironment::AddDSN:
        flag = ODBC_ADD_DSN;
        break;
    case CatEnvironment::ConfigDSN:
        flag = ODBC_CONFIG_DSN;
        break;
    case CatEnvironment::RemoveDSN:
        flag = ODBC_REMOVE_DSN;
        break;
    case CatEnvironment::AddSysDSN:
        flag = ODBC_ADD_SYS_DSN;
        break;
    case CatEnvironment::ConfigSysDSN:
        flag = ODBC_CONFIG_SYS_DSN;
        break;
    case CatEnvironment::RemoveSysDSN:
        flag = ODBC_REMOVE_SYS_DSN;
        break;
    default:
        break;
    }

	if (!SQLConfigDataSourceW(NULL, flag, sDriver.c_str(), attributesString))
    {
        g_hasError = true;
        DWORD err = GetLastError();
        g_errorMsg = "GetLastError()=" + std::to_string(err);
        return false;
    }
    return true;
}

bool CatEnvironmentImp::configDSNByFile(const wchar_t* dsnFile, const wchar_t* DSNName,
    const wchar_t* driver/* = NULL*/, ConfigDsnAction action/* = AddDSN*/)
{
    std::wstring attString;

    attString.append(L"DSN=");
    attString.append(DSNName);
    attString.append(1, '\0');

    wchar_t* sz = new wchar_t[40960];
    GetPrivateProfileSectionW(L"ODBC", sz, 40960, dsnFile);
    wchar_t* p = sz;
    while (*p)
    {
        wchar_t* kvstr = p;
        attString.append(kvstr);
        attString.append(1, '\0');
        p += wcslen(p) + 1;
    }
    delete[] sz;
    attString.append(1, '\0');

    return configDSN(&attString[0], driver, action);
}

bool CatEnvironmentImp::isDriverInstalled(const char* driver)
{
    g_hasError = false; g_errorMsg.clear();
    try
    {
        return m_raw->isDriverInstalled(driver);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}

CatDataSourceInformations* CatEnvironmentImp::getDataSources()
{
    std::vector<DataSourceInformation> info = m_raw->getDataSources();
    return new CatDataSourceInformationsImp(info);
}

CatDataSourceInformations* CatEnvironmentImp::getDataSources(CatDSNType dsnType)
{
    std::vector<DataSourceInformation> info = m_raw->getDataSources((DSNType)dsnType);
    return new CatDataSourceInformationsImp(info);
}

CatDriverInformations* CatEnvironmentImp::getDrivers()
{
    std::vector<DriverInformation> info = m_raw->getDrivers();
    return new CatDriverInformationsImp(info);
}
