#include "pch.h"
#include "CatEnvironmentImp.h"
#include "CatConnectionImp.h"
#include <odbcinst.h>
#include <algorithm>
#pragma comment(lib, "legacy_stdio_definitions.lib")

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

bool CatEnvironmentImp::createDSN(const wchar_t* attributesString, 
    const wchar_t* driver/* = NULL*/, bool sysDsn/* = false*/)
{
    g_hasError = false;

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

	if (!SQLConfigDataSourceW(NULL, (sysDsn ? ODBC_ADD_SYS_DSN : ODBC_ADD_DSN), sDriver.c_str(), attributesString))
    {
        g_hasError = true;
        DWORD err = GetLastError();
        g_errorMsg = "GetLastError()=" + std::to_string(err);
        return false;
    }
    return true;
}

bool CatEnvironmentImp::createDSNByFile(const wchar_t* dsnFile, const wchar_t* DSNName,
    const wchar_t* driver/* = NULL*/, bool sysDsn/* = false*/)
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

    return createDSN(&attString[0], driver, sysDsn);
}
