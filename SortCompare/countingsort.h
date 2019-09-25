#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <QObject>
#include<QThread>

class CountingSort : public QObject
{
    Q_OBJECT
public:
    explicit CountingSort(QObject *parent = nullptr);
    explicit CountingSort(int l,int max,int md,int *array,QObject *parent = nullptr);
    int *data;
    int length;
    int cur;
    int mDelay;
    int max=100;
    void countingSort(int  *a,int length);
    void goCountingSort();//处理排序算法
signals:
    void countingSignal(int cur);
    void finishedSignal();
public slots:
};

#endif // COUNTINGSORT_H
