#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include<QThread>

class QuickSort : public QObject
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    explicit QuickSort(int l,int md,int *array,QObject *parent = nullptr);
    int *data;
    int length;
    int cur;
    int mDelay;
    void swap(int &a,int &b);
    int Parritition(int *a,int p,int r);
    void QuckSort(int *a,int p,int r);
    void goQuickSort();//处理排序算法

signals:
  void quickSignal(int cur);
  void finishedSignal();
public slots:
};

#endif // QUICKSORT_H
