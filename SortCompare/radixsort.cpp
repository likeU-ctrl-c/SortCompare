#include "radixsort.h"

RadixSort::RadixSort(QObject *parent) : QObject(parent)
{

}
RadixSort::RadixSort(int l,int max,int md,int *array,QObject *parent) : QObject(parent)
{
    length=l;
    this->max=max;
    this->mDelay=md;
    this->data=array;
}
//按照某位数将数字推入到队列中
void RadixSort::VecToDeque(QVector<int> &vec, QQueue<int> *deq, int n){
    QVector<int>::iterator it;
        for (it = vec.begin(); it != vec.end(); it++)
        {
            int itor = (*it) / n % 10;
            deq[itor].enqueue(*it);
        }
}
//将队列中按照某位数排好的数字输出到容器
void RadixSort::Colect(QVector<int>&vect, QQueue<int>deq[]){
    int count = 0;
        for (int i = 0; i < 10; i++)
        {
            while (!deq[i].empty())
            {
                vect[count] = deq[i].front();
                count++;
                deq[i].dequeue();
            }
        }

}
//求队列中的最大数的位数
int RadixSort::Max(QVector<int>&vec){
    QVector<int>::iterator it;
        it = vec.begin();
        int max = *it;
        for (it = vec.begin(); it != vec.end(); it++)
        {
            if (max < *it)
            {
                max = *it;
            }
        }
        int count = 1;
        while (max >= 10)
        {
            max /= 10;
            count++;
        }
        return count;
}

void RadixSort::Array2Vector(QVector<int>&vec,int *a,int n){
    for(int i=0;i<n;i++){
            vec[i]=a[i];
        }
}
void RadixSort::Vector2Array(QVector<int>&vec,int *a,int n){
    for(int i=0;i<n;i++){
            a[i]=vec[i];
        }
}
//调用VecToDeque和Colect对数字进行排序
void RadixSort::radixSort(QVector<int>&vec){
    int count = Max(vec);
        int power = 1;

        QQueue<int> que[qFloor(max/10)];
        for (int i = 1; i <= count; i++)
        {
            VecToDeque(vec, que, power);
            Colect(vec, que);
            power *= 10;
        }
}
//处理排序算法
void RadixSort::goRadixSort(){
        QVector<int>vec(length);
        Array2Vector(vec,data,length);
        radixSort(vec);
        Vector2Array(vec,data,length);
        for(int i=0;i<length;i++){
            radixSignal(i);
           QThread::msleep(static_cast<unsigned int>(mDelay));
        }
finishedSignal();
}



