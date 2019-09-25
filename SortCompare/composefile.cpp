#include "composefile.h"
#include<QVector>
#include<ctime>
#include<QFile>
#include<QDebug>
#include<QProcess>


//合并文件
ComposeFile::ComposeFile()
{

}
//产生随机数的代码
void ComposeFile::makeRandomArray(int length,int min,int max){
    this->length=length;
    this->max=max;
    this->min=min;
   //定义一个数组；
    QVector<int>array;

   //1.产生随机数
   //产生随机数组
    qsrand(time(NULL));
   for(int i=0;i<length;i++){
        int randNum=qrand()%max+min;
        array.append(randNum);
   }
    //2.将产生的随机数写入文件中
    QFile f(path);
    bool isOk = f.open(QIODevice::WriteOnly|QIODevice::Text);

    if(isOk){
        //遍历Vector
        QVector<int>::iterator iter;
        for(iter=array.begin();iter!=array.end();iter++){
            QString num=QString::number(*iter,10)+ "\n";
            //写入文件
            f.write(num.toUtf8());
        }
    }
    f.close();
}

void ComposeFile::makeCode(QString code,QString funName){

//1.定义运行的代码+用户的代码

    QString RunCode="#include <iostream>\n";
     RunCode=RunCode+"#include <fstream>\n"+
      "#include<string>\n"+
        "using namespace std;\n"+code+
        "\n const int MAX_NUM ="+QString::number(length)+";\n"+
       " int ARRAY_MAX_NUM[MAX_NUM];     \n"+
       " const char* _test_data_path=\""+path+"\";\n"+
       " const char* _errLog_=\""+errLogPath+"\";\n"+
       " int total = 0;\n"+
       " void getArray(){\n"+
            " int total = 0;\n"+
            " ifstream srcFile;\n"+
           "  srcFile.open(_test_data_path); \n"+
            " ofstream errFile(_errLog_,ios::out); \n"+
           " if(!srcFile) { \n"+
             "   errFile << "+"\"error opening source file.\"" +"<< endl;\n"+
               " srcFile.close();\n"+
        "    }\n"+
         "   if(!errFile){ \n"+
                " errFile << "+"\"error opening errlog file.\""+" << endl;\n"+
           " }\n"+
           " int x;\n"+
            "while(srcFile >> x)\n"+
               " ARRAY_MAX_NUM[total++] = x;\n"+
           " srcFile.close();\n"+
            "errFile.close();\n"+
    "    }\n"+
      "  void sort(int *array,int length){\n"+
            funName+
       " } \n"+

         "int main()\n"+
       " {\n"+
         "  getArray();\n"+
          " sort(ARRAY_MAX_NUM,MAX_NUM);\n"+
           " return 0;\n"+
       " }\n";
    //2.将代码写入文件
     QFile f(userCodePath);
     bool isOk = f.open(QIODevice::WriteOnly|QIODevice::Text);
     if(isOk){
             f.write(RunCode.toUtf8());
     }
     f.close();
}

void ComposeFile::makeUserCode(QString code){
    //将代码写入文件
     QFile f(userCodePath);
     bool isOk = f.open(QIODevice::WriteOnly|QIODevice::Text);
     if(isOk){
             f.write(code.toUtf8());
     }
     f.close();
}

QString ComposeFile::runCode(){
    //1.编译写的文件
       QProcess p(0);
       p.setWorkingDirectory("d:/");//指定进程的工作目录
       p.start("cl", QStringList()<<"-EHsc "<<"runCode.cpp");
       p.waitForStarted();
       p.waitForFinished();
       p.kill();
       //将编译的结果输出
       QString compileOutput=QString::fromLocal8Bit(p.readAllStandardOutput());
       if(compileOutput.isNull()){
           compileOutput="";
       }else{
          compileOutput= "编译输出"+compileOutput;
       }
       //将编译的错误输出
       QString compileOutErr=QString::fromLocal8Bit(p.readAllStandardError());
       if(compileOutErr.isNull()){
           compileOutErr="";
       }else{
         compileOutErr= "编译出错："+compileOutErr;
       }

    //2.运行写得文件
       QProcess p1;
       p1.setWorkingDirectory("d:\\");//指定进程的工作目录
       p1.start("d:\\runCode.exe");
       p1.start("runcode");
       p1.waitForStarted();
       p1.waitForFinished();
       p1.kill();
       //运行时的输出文件
       QString runOut=QString::fromLocal8Bit(p1.readAllStandardOutput());
       if(runOut.isNull()){
           runOut="";
       }else{
           QFile f(userRousePath);
           bool isOk = f.open(QIODevice::WriteOnly|QIODevice::Text);

           if(isOk){
               f.write(runOut.toUtf8());
           }
           f.close();
          runOut= "运行输出："+runOut;
       }
        //运行时的错误文件
       QString runErr=QString::fromLocal8Bit(p1.readAllStandardError());
       if(runErr.isNull()){
           runErr="";
       }else{
        runErr="运行出错："+runErr;
       }


     // 将结果输出
       QString strTemp=compileOutput+compileOutErr+runOut+runErr;
       qDebug()<<strTemp;
       return strTemp;
}

