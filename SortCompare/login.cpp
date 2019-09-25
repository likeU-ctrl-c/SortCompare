#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::receiveshow(){
    this->show();//显示登录对话框
}

void Login::on_pushButton_clicked(){
     emit quit();//发射退出信号
}

void Login::on_pushButton_2_clicked()
{

    this->hide();//隐藏登录窗口
    emit showMainWindow();//显示主窗口
}
