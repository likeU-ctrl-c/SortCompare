#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"insertionsort.h"
#include"writecode.h"
#include"usercode.h"
#include"sortshow.h"
#include"tspanddfs.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SortShow *sortShow;


private:
    Ui::MainWindow *ui;

private slots:
    void receivelogin();//与longin中发射的信号关联的槽函数
    void on_pushButton_clicked();//与relogin的click（）关联的槽函数
    void on_pushButton_2_clicked();  //与quit的click（）关联的槽函数
    void loadUserCode();//显示用户大段显示窗口
    void loadWriteCode();//显示排序算法窗口
    void sortPlay();//显示排序算法的窗口
    void InsertionSortShow();//显示插入排序的窗口；
    void MergeSortShow();//显示归并排序的窗口；
    void quickSortShow();//显示快速排序的窗口；
    void heapSortShow();//显示堆排序的窗口；
    void countingSortShow();//显示计数排序的窗口；
    void radixSortShow();//显示基数排序的窗口；
    void tspShow();//旅行商窗口显示





 signals:
    void showUserCodeDlg();
    void dlgshow();//显示登录对话框信号
    void quit();//退出信号
    void sortId(int id);//排序算法的id；

};


#endif // MAINWINDOW_H
