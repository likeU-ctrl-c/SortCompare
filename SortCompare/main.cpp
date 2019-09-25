#include "mainwindow.h"
#include <QApplication>
#include"login.h"
#include"composefile.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login log;
    log.show();

    //信号与槽进行关联
    QObject::connect(&log,SIGNAL(showMainWindow()),&w,SLOT(receivelogin()));
    QObject::connect(&w,SIGNAL(dlgshow()),&log,SLOT(receiveshow()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&log,SIGNAL(quit()),&a,SLOT(quit()));



//    ComposeFile cf;
//    cf.makeRandomArray(100);
//    QString s="void fun(int* array,int length){\ncout<<";
//    s=s+"\"这是代码用户区"+"\""+"<"+"< endl;\n"+
//                    "for(int i=0;i<length;i++){cout<<array[i];}"
//                                  +"}\n";
//    QString num="fun(array,length);cout<<";
//    num=num+"\"这是方法调用区"+"\""+"<<endl;";
//    cf.makeCode(s,num);

    return a.exec();
}
