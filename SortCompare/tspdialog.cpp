#include "tspdialog.h"
#include "ui_tspdialog.h"


TSPDialog::TSPDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TSPDialog)
{
    ui->setupUi(this);

}

TSPDialog::~TSPDialog()
{
    delete ui;
}

void TSPDialog::on_buttonBox_accepted()
{

}
void TSPDialog::accept(){
    cityNum=ui->spinBox->text().toInt();
    max = ui->spinBox_3->text().toInt();
    min = ui->spinBox_2->text().toInt();
    emit receive(cityNum,max,min);
    this->close();
}

void TSPDialog::on_buttonBox_rejected()
{

}
