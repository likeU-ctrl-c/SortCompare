#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <QObject>
#include <QThread>
class InsertionSort : public QObject
{
    Q_OBJECT
public:
    explicit InsertionSort(int l,int md,int *array,QObject *parent = nullptr);
    int *data;
    int length;
    int cur;
    int mDelay;
    void goInsertionSort();//处理排序算法

signals:
    void insertionSignal(int curi,int curj,int key);//发送当前排序的位置
    void finishedSignal();//结束排序信号
public slots:
};

#endif // INSERTIONSORT_H
