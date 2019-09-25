#ifndef TSPANDDFS_H
#define TSPANDDFS_H

#include <QWidget>
#include"dfs.h"
#include<QThread>
#include"tspandbbalgorithm.h"
#include"ww_tsp_bfs.h"

namespace Ui {
class TSPandDFS;
}

class TSPandDFS : public QWidget
{
    Q_OBJECT

public:
    explicit TSPandDFS(QWidget *parent = nullptr);
    ~TSPandDFS();
    int type=0;//0表示没有运行1表示没有剪枝2表示剪枝运行
    int cityNum=5;//城市的数量
    int max=100;  //随机数的最大值
    int min=1;  //随机数的最小值
    int *OPTpath=nullptr;
    int width;//窗口的宽度
    int height;//窗口的高度
    int *cityX=nullptr;//城市x的坐标
    int *cityY=nullptr;//城市Y的坐标
    TSPAndBBAlgorithm *tspbb;//剪枝算法
    QThread *qthread;//线程2
    bool flag=true;//定义画图
    DFS *dfs; //定义全局dfs算法
    void paintEvent(QPaintEvent *);

signals:
    void start();
    void startBB();//开始剪枝算法
public slots:
    void on_pushButton_clicked();
    void updateData(int cityNum,int max,int min);

    void on_pushButton_2_clicked();
    void dfsDeal(int curMinWidth,int nodeNum);
    void dfsFinishDeal();

    void on_pushButton_3_clicked();

private:
    Ui::TSPandDFS *ui;
};

#endif // TSPANDDFS_H
