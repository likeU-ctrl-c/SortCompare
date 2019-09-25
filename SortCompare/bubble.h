#ifndef BUBBLE_H
#define BUBBLE_H

#include <QObject>
#include <QThread>
#include <QTime>
class Bubble : public QObject
{
    Q_OBJECT
public:
    explicit Bubble(int l,int m,int mD,int *data,QObject *parent = nullptr);
    void goBubble();      //处理排序算法
    void rand();    //随机产生数据
    int length;     //数组的长度
    int *data;      //数组
    int max;        //单个数据的最大值
    int cur;        //排序当前处理的位置
    int mDelay;     //延时时间，方便动态展示
signals:
    void bubbleSignal(int cur); //发送当前排序的位子
private:

public slots:
};

#endif // BUBBLE_H
