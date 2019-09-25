#include "writecode.h"
#include "ui_writecode.h"
#include"composefile.h"

WriteCode::WriteCode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WriteCode)
{
     ui->setupUi(this);
    //头部标签的设置
    QString header="#include <iostream>\n";
      header+="#include <fstream>\n" ;
       header+="#include<string>\n" ;
      header+="using namespace std;\n" ;
    ui->textEdit->setText(header);
    //中间函数实现的设置
    QString centerCode="void sort(int *array,int length){";
    QString centerCode2="}";
    ui->lineEdit_2->setText(centerCode);
    ui->lineEdit_3->setText(centerCode2);

    //主函数的代码显示
    QString main=" int main()\n";
    main+="{\n";
    main+="getArray();\n";
    main+="sort(ARRAY_MAX_NUM,MAX_NUM);\n";
    main+="return 0;\n";
    main+=" }\n";
    ui->textEdit_3->setText(main);


    //测试代码
    QString testCODE="void fun(){\n";
    testCODE+="cout<<\" shafasljfla有个hsjfhk \" <<endl;\n";
    testCODE+="}";
    ui->codeEdit->setText(testCODE);
    QString testfun="fun();";
    ui->funNameEdit->setText(testfun);

}

WriteCode::~WriteCode()
{
    delete ui;
}

void WriteCode::on_pushButton_clicked()
{
    ComposeFile *cf=new ComposeFile();
          QString code= ui->codeEdit->toPlainText();
          QString funName=ui->funNameEdit->text();
          cf->makeCode(code,funName);
         QString rose= cf->runCode();
         ui->cmd_edit->setPlainText(rose);

}
