#ifndef TSPDIALOG_H
#define TSPDIALOG_H

#include <QDialog>

namespace Ui {
class TSPDialog;
}

class TSPDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TSPDialog(QWidget *parent = nullptr);
    ~TSPDialog();
    int cityNum;
    int max;
    int min;
    void accept();
signals:
    void receive(int cityNum,int max,int min);
private slots:
    void on_buttonBox_accepted();


    void on_buttonBox_rejected();

private:
    Ui::TSPDialog *ui;
};

#endif // TSPDIALOG_H
