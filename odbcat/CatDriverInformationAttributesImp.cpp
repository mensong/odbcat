#include "pch.h"
#include "CatDriverInformationAttributesImp.h"

CatDriverInformationAttributesImp::CatDriverInformationAttributesImp(std::vector<DriverInformation::Attribute>& ref)
    : m_raw(ref)
{
}

int CatDriverInformationAttributesImp::count()
{
    return m_raw.size();
}

const char* CatDriverInformationAttributesImp::name(int idx)
{
    return m_raw[idx].name.c_str();
}

const char* CatDriverInformationAttributesImp::value(int idx)
{
    return m_raw[idx].value.c_str();
}
