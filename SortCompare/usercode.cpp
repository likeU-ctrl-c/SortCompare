#include "usercode.h"
#include "ui_usercode.h"
#include "composefile.h"
#include <QString>

UserCode::UserCode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserCode)
{
    ui->setupUi(this);
}

UserCode::~UserCode()
{
    delete ui;
}
void UserCode::WriteCode2File(){

}

void UserCode::on_pushButton_2_clicked()
{
ui->textEdit->setText("");
ui->textEdit_2->setText("");
}

void UserCode::on_pushButton_clicked()
{
    QString code = ui->textEdit_2->toPlainText();
    ComposeFile cf;
    cf.makeUserCode(code);
    QString ruse=cf.runCode();
    ui->textEdit->setText(ruse);
}
