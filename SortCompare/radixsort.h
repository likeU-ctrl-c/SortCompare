#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <QObject>
#include<QVector>
#include <QQueue>
#include<QtMath>
#include<QThread>
class RadixSort : public QObject
{
    Q_OBJECT
public:
    explicit RadixSort(QObject *parent = nullptr);
    explicit RadixSort(int l,int max,int md,int *array,QObject *parent = nullptr);

    int *data;
    int length;
    int cur;
    int mDelay;
    int max=100;

    void VecToDeque(QVector<int>&vec, QQueue<int>deq[], int n);//按照某位数将数字推入到队列中
    void Colect(QVector<int>&vect, QQueue<int>deq[]);//将队列中按照某位数排好的数字输出到容器中
    int Max(QVector<int>&vec); //求队列中的最大数的位数
    void Array2Vector(QVector<int>&vec,int *a,int n);
    void Vector2Array(QVector<int>&vec,int *a,int n);
    void radixSort(QVector<int>&vec);//调用VecToDeque和Colect对数字进行排序
    void goRadixSort();//处理排序算法

signals:
    void radixSignal(int cur);
    void finishedSignal();
public slots:
};

#endif // RADIXSORT_H
