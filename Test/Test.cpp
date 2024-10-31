// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "..\odbcat\odbcat.h"

#define CHECK_E() if (odbcat::Ins().HasError()) {std::cout << odbcat::Ins().GetError() << std::endl; return 1;}

int main()
{
    auto env = odbcat::Ins().CreateEnvironment();
    CATSCOPE(env);

    std::cout << "已安装的ODBC驱动:" << std::endl;
    auto drivers = env->getDrivers();
    for (int i = 0; i < drivers->count(); i++)
    {
        std::cout << "#" << i << " - " << drivers->description(i) << std::endl;
        auto attis = drivers->attributes(i);

        for (int j = 0; j < attis->count(); j++)
        {
            std::cout << " " << attis->name(j) << " : " << attis->value(j) << std::endl;
        }

        std::cout << std::endl;
    }
    odbcat::Ins().CatFreeT(&drivers);
    std::cout << std::endl;

    std::cout << "已存在的数据源:" << std::endl;
    auto dss = env->getDataSources();
    for (int i = 0; i < dss->count(); i++)
    {
        std::cout << dss->name(i) << " : " << dss->description(i) << std::endl;
    }
    odbcat::Ins().CatFreeT(&dss);
    std::cout << std::endl;

    std::cout << "测试驱动是否可用:" << std::endl;
    bool installed = env->isDriverInstalled("Microsoft Access Driver (*.mdb, *.accdb)");
	std::cout << "Microsoft Access Driver (*.mdb, *.accdb) " << (installed ? "可用" : "不可用") << std::endl;
    installed = env->isDriverInstalled("Microsoft Access Driver (*.mdb)");
    std::cout << "Microsoft Access Driver (*.mdb) " << (installed ? "可用" : "不可用") << std::endl;
    std::cout << std::endl;

    bool b;

	b = env->configDSN(
		L"DSN=MyDSN\0\0", 
#if _WIN64
        L"Microsoft Access Driver (*.mdb, *.accdb)", 
#else
        L"Microsoft Access Driver (*.mdb)",
#endif
        CatEnvironment::RemoveDSN);

    //bool b = env->configDSN(
    //    L"DSN=MyDSN\0"
    //    L"DRIVER=Microsoft Access Driver (*.mdb, *.accdb)\0"
    //    L"UID=\0"
    //    L"UserCommitSync=Yes\0"
    //    L"Threads=3\0"
    //    L"SafeTransactions=0\0"
    //    L"PageTimeout=5\0"
    //    L"MaxScanRows=8\0"
    //    L"MaxBufferSize=2048\0"
    //    L"FIL=MS Access\0"
    //    L"DriverId=25\0"
    //    L"DefaultDir=E:\\\0"
    //    L"DBQ=E:\\Database1.mdb\0"
    //    L"\0", NULL, CatEnvironment::ConfigDSN);

    std::vector<std::wstring> iniKeys;
    iniKeys.push_back(L"DSN=MyDSN");
#if _WIN64
    iniKeys.push_back(L"DRIVER=Microsoft Access Driver (*.mdb, *.accdb)");
#else    
    iniKeys.push_back(L"DRIVER=Microsoft Access Driver (*.mdb)");
#endif
    iniKeys.push_back(L"UID=");
    iniKeys.push_back(L"UserCommitSync=Yes");
    iniKeys.push_back(L"Threads=3");
    iniKeys.push_back(L"SafeTransactions=0");
    iniKeys.push_back(L"PageTimeout=5");
    iniKeys.push_back(L"MaxScanRows=8");
    iniKeys.push_back(L"FIL=MS Access");
    iniKeys.push_back(L"DriverId=25");
    wchar_t curDir[MAX_PATH] = { 0 };
    GetCurrentDirectoryW(MAX_PATH, curDir);
    iniKeys.push_back(L"DefaultDir=" + std::wstring(curDir));
    iniKeys.push_back(L"DBQ=" + std::wstring(curDir) + L"\\Database1.mdb");
    std::wstring attrStr;
    for (size_t i = 0; i < iniKeys.size(); i++)
    {
        attrStr.append(iniKeys[i]);
        attrStr.append(1, '\0');
    }
    attrStr.append(1, '\0');
    b = env->configDSN(attrStr.c_str(), NULL, CatEnvironment::AddDSN);
    CHECK_E();

    auto conn = env->createConnection();
    CATSCOPE(conn);
    CHECK_E();
    b = conn->connectByDSNName("MyDSN");
    //b = conn->connect("DRIVER=Microsoft Access Driver (*.mdb, *.accdb);UID=;UserCommitSync=Yes;Threads=3;SafeTransactions=0;PageTimeout=5;MaxScanRows=8;FIL=MS Access;DriverId=25;DefaultDir=E:;DBQ=E:\\Database2.accdb;");
    CHECK_E();
    b = conn->connected();
    auto stmt = conn->createStatement();
    CATSCOPE(stmt);
    CHECK_E();
    auto res = stmt->executeQuery("SELECT * FROM tab1;");
    CATSCOPE(res);
    CHECK_E();

    std::cout << "列出结果集:" << std::endl;
    auto md = res->getMetaData();
    CATSCOPE(md);
    int colCount = md->getColumnCount();
    for (int i = 0; i < colCount; i++)
    {
        std::string name = md->getColumnName(i);
        //std::string stype = md->getColumnTypeName(i);
        //int type = md->getColumnType(i);
        std::cout << name << "\t\t";
    }

    std::cout << std::endl;
    while (res->next())
    {
        for (int i = 0; i < colCount; i++)
        {
            CatColumnType type = md->getColumnType(i);
            switch (type)
            {
            case CT_UNKNOWN_TYPE:
            {
                std::cout << "<NA>" << "\t\t";
            }
                break;
            case CT_CHAR:
            {
                bool isNull = false;
                auto v = res->getByte(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string((char)v)) << "\t\t";
            }
                break;
            case CT_NUMERIC:
            {
                bool isNull = false;
                auto v = res->getDouble(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_DECIMAL:
            {
                bool isNull = false;
                auto v = res->getDouble(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_INTEGER:
            {
                bool isNull = false;
                int v = res->getInt(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_SMALLINT:
            {
                bool isNull = false;
                auto v = res->getShort(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_FLOAT:
            {
                bool isNull = false;
                auto v = res->getFloat(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_REAL:
            {
                bool isNull = false;
                auto v = res->getLong(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_DOUBLE:
            {
                bool isNull = false;
                auto v = res->getDouble(i, &isNull);
                std::cout << (isNull ? "(null)" : std::to_string(v)) << "\t\t";
            }
                break;
            case CT_DATETIME:
            {
                bool isNull = false;
                int year = 0, month = 0, day = 0,
                    hour = 0, minute = 0, second = 0, milliseconds = 0;
                auto v = res->getTimestamp(i, &year, &month, &day,
                    &hour, &minute, &second, &milliseconds, &isNull);
                std::cout << (isNull ? "(null)" : 
                    std::to_string(year) +    "-" + 
                    std::to_string(month) +   "-" +
                    std::to_string(day) +     " " +
                    std::to_string(hour) +    ":" +
                    std::to_string(minute) +  ":" +
                    std::to_string(second)
                    ) << "\t\t";
            }
                break;
            case CT_VARCHAR:
            {
                bool isNull = false;
                size_t len = res->getStringLength(i, &isNull);
                if (len)
                {
                    char* buff = new char[len + 1];
                    buff[len] = '\0';
                    res->getStringData(1, buff, len + 1);
                    std::cout << buff;
                    delete[] buff;
                }
                if (isNull)
                {
                    std::cout << "(null)";
                }
                std::cout << "\t\t";
            }
                break;
            case CT_TYPE_DATE:
            {
                bool isNull = false;
                int year = 0, month = 0, day = 0;
                auto v = res->getDate(i, &year, &month, &day, &isNull);
                std::cout << (isNull ? "(null)" :
                    std::to_string(year) + "-" +
                    std::to_string(month) + "-" +
                    std::to_string(day) 
                    ) << "\t\t";
            }
                break;
            case CT_TYPE_TIME:
            {
                bool isNull = false;
                int hour = 0, minute = 0, second = 0;
                auto v = res->getTime(i, &hour, &minute, &second, &isNull);
                std::cout << (isNull ? "(null)" :
                    std::to_string(hour) + ":" +
                    std::to_string(minute) + ":" +
                    std::to_string(second)
                    ) << "\t\t";
            }
                break;
            case CT_TYPE_TIMESTAMP:
            {
                bool isNull = false;
                int year = 0, month = 0, day = 0,
                    hour = 0, minute = 0, second = 0, milliseconds = 0;
                auto v = res->getTimestamp(i, &year, &month, &day,
                    &hour, &minute, &second, &milliseconds, &isNull);
                std::cout << (isNull ? "(null)" :
                    std::to_string(year)   + "-" + 
                    std::to_string(month)  + "-" +
                    std::to_string(day)    + " " +
                    std::to_string(hour)   + ":" +
                    std::to_string(minute) + ":" +
                    std::to_string(second) + ":" +
                    std::to_string(milliseconds)
                    ) << "\t\t";
            }
                break;
            default:
                break;
            }
        }
        std::cout << std::endl;
    }
    
    //odbcat::Ins().CatFreeT(&md);
    //odbcat::Ins().CatFreeT(&res);
    //odbcat::Ins().CatFreeT(&stmt);
    //odbcat::Ins().CatFreeT(&conn);
    //odbcat::Ins().CatFreeT(&env);

    return 0;
}
