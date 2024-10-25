#include "pch.h"
#include "CatDriverInformationsImp.h"
#include "CatDriverInformationAttributesImp.h"

CatDriverInformationsImp::CatDriverInformationsImp(std::vector<DriverInformation>& ref)
    : m_raw(ref)
{
}

int CatDriverInformationsImp::count()
{
    return m_raw.size();
}

const char* CatDriverInformationsImp::description(int idx)
{
    return m_raw[idx].description.c_str();
}

CatDriverInformationAttributes* CatDriverInformationsImp::attributes(int idx)
{
    return new CatDriverInformationAttributesImp(m_raw[idx].attributes);
}
