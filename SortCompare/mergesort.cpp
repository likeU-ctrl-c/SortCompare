#include "mergesort.h"

MergeSort:: MergeSort(int l,int mD,int *data,QObject *parent):QObject (parent)
{
    length=l;
    mDelay=mD;
    this->array=data;
}
//合并堆函数
void MergeSort::Merge(int *a, int p, int q, int r){
    int n1=q-p+1; //计算左边数组长度
    int n2=r-q;  //计算右边数组长度
    int *L = new int[n1+1]; //申请左边数组
    int *R = new int[n2+1];  //申请右边数组

    for(int i=0;i<n1;i++){
        L[i]=a[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=a[q+j+1];
    }
    L[n1]=99999999;
    R[n2]=99999999;
    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i=i+1;
            mergeSignal(k);
            QThread::msleep(static_cast<unsigned long>(mDelay));
        }else{
            a[k]=R[j];
            j=j+1;
            mergeSignal(k);
            QThread::msleep(static_cast<unsigned long>(mDelay));
        }
    }

    delete [] L;
    delete [] R;


}
//分堆函数
void MergeSort::MERGE_Sort(int *a, int p, int r){
    if(p<r){
        int q=(p+r)/2;
        MERGE_Sort(a,p,q);
        MERGE_Sort(a,q+1,r);
        Merge(a,p,q,r);
    }

}
//运行堆函数
void MergeSort::goMERGESort(){
    MERGE_Sort(array,0,length);
    finishedSignal();
}
