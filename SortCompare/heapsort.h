#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QObject>
#include<QThread>

class HeapSort : public QObject
{
    Q_OBJECT
public:
    explicit HeapSort(QObject *parent = nullptr);
    explicit HeapSort(int l,int md,int *array,QObject *parent = nullptr);
    int *data;
    int length;
    int cur;
    int mDelay;
    void swap(int &a,int &b);
    void max_heapify(int *arr,int start,int end);
    void heapSort(int *arr,int len);
    void goHeapSort();//处理排序算法

signals:
  void heapSignal(int cur);
  void finishedSignal();
public slots:
};

#endif // HEAPSORT_H
