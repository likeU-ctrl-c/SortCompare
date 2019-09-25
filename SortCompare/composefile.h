#ifndef COMPOSEFILE_H
#define COMPOSEFILE_H
#include <QString>
#include<QVector>


class ComposeFile
{
public:
    ComposeFile();
    QString path="d:\\\\test.txt";//随机数文件的地址；要用四个\表示。
    QString errLogPath="d:\\\\errLog.txt";//错误日志文件位置
    QString userCodePath="d:\\\\runCode.cpp";//用户代码运行的文件;
    QString userDirPath="d:\\";
    QString userRousePath="d:\\userRouse.txt";
    int length=100;
    int min=0;
    int max=100;

    //1.生成随机数 并将产生的随机数写入文件
    void makeRandomArray(int length=100,int min=0,int max=100);
    //2.读取随机数和写入的代码 合并代码生成代码文件
    void makeCode(QString code,QString funName);

    //用户自己写代码运行
    void makeUserCode(QString code);
    //3.运行代码文件并返回结果；
    QString runCode();
};





#endif // COMPOSEFILE_H
