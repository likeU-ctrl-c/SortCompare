#ifndef MERGESORT_H
#define MERGESORT_H
#include<QObject>
#include<QThread>

class MergeSort :public QObject
{
    Q_OBJECT
public:
   explicit MergeSort(int l,int mD,int *data,QObject *parent = nullptr);
    int *array; //定义数组
    int length;//定义长度
    int mDelay;//定义线程休息时间

    void Merge(int *a,int p,int q,int r); //合并堆函数
    void MERGE_Sort(int *a,int p,int r);//分堆函数
    void goMERGESort(); //运行堆函数


signals:
    void mergeSignal(int cur); //发送当前排序的位子
    void finishedSignal();
private:

public slots:

};

#endif // MERGESORT_H
