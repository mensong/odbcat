// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "..\odbcat\odbcat.h"

int main()
{
    auto odbc = odbcat::Ins().CreateEnvironment();

    bool b = odbc->createDSN(
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
        L"\0");

    auto conn = odbc->createConnection();
    b = conn->connectByDSNName("MyDSN");
    b = odbcat::Ins().HasError();
    std::string errMsg = odbcat::Ins().GetError();
    b = conn->connected();
    auto stmt = conn->createStatement();
    auto res = stmt->executeQuery("SELECT * from tab1;");
    errMsg = odbcat::Ins().GetError();

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
    odbcat::Ins().CatFreeT(&odbc);

    return 0;
}
