#include "pch.h"
#include "odbcat.h"
#include "CatEnvironmentImp.h"

ODBCAT_API CatEnvironment* CreateEnvironment()
{
    return new CatEnvironmentImp();
}

ODBCAT_API void CatFree(CatBase** pp)
{
    if (pp && *pp)
    {
        delete *pp;
        *pp = NULL;
    }
}

bool g_hasError = false;
std::string g_errorMsg;

ODBCAT_API bool HasError()
{
    return g_hasError;
}

ODBCAT_API const char* GetError()
{
    return g_errorMsg.c_str();
}
