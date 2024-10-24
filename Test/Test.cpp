// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "..\odbcat\odbcat.h"

int main()
{
    auto odbc = odbcat::Ins().CreateEnvironment();
    auto conn = odbc->createConnection();
    bool b = conn->connectByDSNName("dsn1");
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
    }

    while (res->next())
    {
        int id = res->getInt(0);

        size_t len = res->getStringLength(1);
        if (len)
        {
            char* buff = new char[len + 1];
            buff[len] = '\0';
            res->getStringData(1, buff, len + 1);
            delete[] buff;
        }

        int age = res->getInt(2);
    }
    
    odbcat::Ins().CatFreeT(&md);
    odbcat::Ins().CatFreeT(&res);
    odbcat::Ins().CatFreeT(&stmt);
    odbcat::Ins().CatFreeT(&conn);
    odbcat::Ins().CatFreeT(&odbc);

    return 0;
}
