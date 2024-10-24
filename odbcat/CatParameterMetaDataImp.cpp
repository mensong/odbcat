#include "pch.h"
#include "CatParameterMetaDataImp.h"

extern bool g_hasError;
extern std::string g_errorMsg;

CatParameterMetaDataImp::CatParameterMetaDataImp(ParameterMetaDataRef ref)
    : m_raw(ref)
{
}

unsigned short CatParameterMetaDataImp::getParameterCount()
{
    g_hasError = false;
    try
    {
        return m_raw->getParameterCount();
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

short CatParameterMetaDataImp::getParameterType(unsigned short paramIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getParameterType(paramIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

size_t CatParameterMetaDataImp::getParameterSize(unsigned short paramIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getParameterSize(paramIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned short CatParameterMetaDataImp::getPrecision(unsigned short paramIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getPrecision(paramIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

unsigned short CatParameterMetaDataImp::getScale(unsigned short paramIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->getScale(paramIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return 0;
    }
}

bool CatParameterMetaDataImp::isNullable(unsigned short paramIndex)
{
    g_hasError = false;
    try
    {
        return m_raw->isNullable(paramIndex + 1);
    }
    catch (const std::exception& ex)
    {
        g_hasError = true;
        g_errorMsg = ex.what();
        return false;
    }
}
