#ifndef SORTSHOW_H
#define SORTSHOW_H
#include <QVector>
#include <QWidget>
#include"insertionsort.h"
#include"bubble.h"
#include"mergesort.h"
#include"quicksort.h"
#include"heapsort.h"
#include"countingsort.h"
#include"radixsort.h"


namespace Ui {
class SortShow;
}

class SortShow : public QWidget
{
    Q_OBJECT


public:
    explicit SortShow(QWidget *parent = nullptr);
    ~SortShow();


    QVector<int> intArray;
    int sortId;//给每个排序算法编号；
    int width;  //窗口的宽度
    int height; //窗口的高度
    int arrayMax; //获得的数组的最大值
    int *array;  //得到的数组
    int size;   //数组的长度
    int cur=0;  //排序时的当前下标
    int key=0;  //插入排序时的当前要插入的值
    int curi=0;  //插入排序已经排完的长度
    int curj=0;  //插入排序要插入的长度序列



    QThread *thread;   //排序算法的子线程
    //排序算法的子线程；
    InsertionSort *insertionSort;  //插入排序算法
    Bubble * bubble;  //冒泡排序算法
    MergeSort *merge;  //归并排序算法
    QuickSort *quick;  //快速排序
    HeapSort *heap; //堆排序
    CountingSort *counting;//计数排序
    RadixSort *radixSort;//基数排序
    //展示函数的方法
    void paintEvent(QPaintEvent *); //画图事件
    void readArrayFromFile();  //从文件里读取随机数
    void QVector2Arrat();  //将Qvector转成array;
    void playSort();





private:
    Ui::SortShow *ui;


signals:
    void startInsertion();
    void startMerge();
    void startQuick();
    void startHeap();
    void startCounting();
    void startRadix();

public slots:
    void deal(int c);//处理来在子线程的消息；
    void insertionDeal(int curi,int curj,int key);//处理来自插入排序算法的消息
    void showWhichSort(int num);
    void finishedDeal();//处理排序完成后的函数


};

#endif // SORTSHOW_H
