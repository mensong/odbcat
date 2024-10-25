// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "..\odbcat\odbcat.h"

#define CHECK_E() if (odbcat::Ins().HasError()) {std::cout << odbcat::Ins().GetError() << std::endl; return 1;}

int main()
{
    auto env = odbcat::Ins().CreateEnvironment();

    auto drivers = env->getDrivers();
    for (int i = 0; i < drivers->count(); i++)
    {
        std::cout << i << ':' << drivers->description(i) << std::endl;
        auto attis = drivers->attributes(i);

        for (int j = 0; j < attis->count(); j++)
        {
            std::cout << attis->name(j) << ':' << attis->value(j) << std::endl;
        }

        std::cout << std::endl;
    }
    odbcat::Ins().CatFreeT(&drivers);

    auto dss = env->getDataSources();
    for (int i = 0; i < dss->count(); i++)
    {
        std::cout << dss->name(i) << ':' << dss->description(i) << std::endl;
    }
    odbcat::Ins().CatFreeT(&dss);


    if (env->isDriverInstalled("Microsoft Access Driver (*.mdb, *.accdb)"))
    {
        std::cout << "Microsoft Access Driver (*.mdb, *.accdb) 已安装" << std::endl;
    }

    bool b = env->configDSN(
        L"DSN=MyDSN\0"
        L"DRIVER=Microsoft Access Driver (*.mdb, *.accdb)\0"
        L"UID=\0"
        L"UserCommitSync=Yes\0"
        L"Threads=3\0"
        L"SafeTransactions=0\0"
        L"PageTimeout=5\0"
        L"MaxScanRows=8\0"
        L"MaxBufferSize=2048\0"
        L"FIL=MS Access\0"
        L"DriverId=25\0"
        L"DefaultDir=E:\\\0"
        L"DBQ=E:\\Database1.mdb\0"
        L"\0", NULL, CatEnvironment::AddDSN);
    CHECK_E();

    auto conn = env->createConnection();
    CHECK_E();
    b = conn->connectByDSNName("MyDSN");
    CHECK_E();
    b = conn->connected();
    auto stmt = conn->createStatement();
    CHECK_E();
    auto res = stmt->executeQuery("SELECT * from tab1;");
    CHECK_E();

    auto md = res->getMetaData();
    int colCount = md->getColumnCount();
    for (int i = 0; i < colCount; i++)
    {
        std::string name = md->getColumnName(i);
        std::cout << "column" << i << "=" << name << std::endl;
    }

    while (res->next())
    {
        int id = res->getInt(0);
        std::cout << "Id=" << id << std::endl;

        size_t len = res->getStringLength(1);
        if (len)
        {
            char* buff = new char[len + 1];
            buff[len] = '\0';
            res->getStringData(1, buff, len + 1);
            std::cout << "Name=" << buff << std::endl;
            delete[] buff;
        }

        int age = res->getInt(2);
        std::cout << "Age=" << age << std::endl;
    }
    
    odbcat::Ins().CatFreeT(&md);
    odbcat::Ins().CatFreeT(&res);
    odbcat::Ins().CatFreeT(&stmt);
    odbcat::Ins().CatFreeT(&conn);
    odbcat::Ins().CatFreeT(&env);

    return 0;
}
