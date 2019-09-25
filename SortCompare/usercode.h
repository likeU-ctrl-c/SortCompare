#ifndef USERCODE_H
#define USERCODE_H

#include <QWidget>

namespace Ui {
class UserCode;
}

class UserCode : public QWidget
{
    Q_OBJECT

public:
    explicit UserCode(QWidget *parent = nullptr);
    ~UserCode();
    void WriteCode2File();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserCode *ui;
};

#endif // USERCODE_H
