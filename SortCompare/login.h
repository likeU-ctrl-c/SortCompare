#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();//与login关联的槽函数
    void receiveshow();//与relongin发射的信号关联的槽函数
    void on_pushButton_2_clicked();//与exit关联的槽函数

private:
    Ui::Login *ui;
signals:
    void showMainWindow();//显示主窗口的信号
    void quit();//退出信号


};

#endif // LOGIN_H
