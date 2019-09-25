#include "heapsort.h"

HeapSort::HeapSort(QObject *parent) : QObject(parent)
{

}
HeapSort::HeapSort(int l,int md,int *array,QObject *parent): QObject(parent)
{
    length=l;
    mDelay=md;
    this->data=array;
}
void HeapSort::swap(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
void HeapSort::max_heapify(int *arr, int start, int end){
    //建立父节点指标和子节点指标
        int dad = start;
        int son = dad * 2 + 1;
        while(son<=end){    //若子节点指标在范围内才做比较
            if(son+1<=end&&arr[son]<arr[son+1])son++;		//先比较两个子节点大小，选择最大的
            if(arr[dad]>arr[son])						//如果父节点大于子节点代表调整完毕，直接跳出函数
                return;
            else{//否则交换父子内容在继续子节点和孙节点比较
                swap(arr[dad],arr[son]);
                dad=son;
                son=dad*2+1;
            }
            heapSignal(son);
            QThread::msleep(static_cast<unsigned int>(mDelay));
        }
}
void HeapSort::heapSort(int *arr, int len){
        //初始化，i从最后一个父节点开始调整
        for(int i=len/2-1;i>=0;i--)
            max_heapify(arr,i,len-1);
        //先将第一个元素和已经排好的元素前一位交换，在从新调整（刚调整的元素之前的元素），直到排序完毕
        for(int i=len-1;i>0;i--){
            swap(arr[0],arr[i]);
            max_heapify(arr,0,i-1);
        }
}
void HeapSort::goHeapSort(){
    heapSort(data,length);
    for(int i=0;i<length;i++){
        heapSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    finishedSignal();
}
