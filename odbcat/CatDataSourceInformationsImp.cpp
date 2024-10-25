#include "pch.h"
#include "CatDataSourceInformationsImp.h"

CatDataSourceInformationsImp::CatDataSourceInformationsImp(std::vector<DataSourceInformation>& ref)
    : m_raw(ref)
{
}

int CatDataSourceInformationsImp::count()
{
    return m_raw.size();
}

const char* CatDataSourceInformationsImp::name(int idx)
{
    return m_raw[idx].name.c_str();
}

const char* CatDataSourceInformationsImp::description(int idx)
{
    return m_raw[idx].description.c_str();
}
