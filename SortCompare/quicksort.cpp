#include "quicksort.h"

QuickSort::QuickSort(QObject *parent) : QObject(parent)
{

}
QuickSort::QuickSort(int l,int md,int *array,QObject *parent):QObject (parent)
{
    length =l;
    mDelay = md;
    this->data=array;
}
void QuickSort::swap(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
int QuickSort::Parritition(int *a, int p, int r){
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(a[j]<=x){
            i=i+1;
           swap(a[i],a[j]);
           quickSignal(j);
           QThread::msleep(static_cast<unsigned int>(mDelay));
        }
    }
    swap(a[i+1],a[r]);
        return i+1;
}
void QuickSort::QuckSort(int *a,int p,int r){
    if(p<r){
        int q=Parritition(a,p,r);
        QuckSort(a,p,q-1);
        QuckSort(a,q+1,r);
    }
}

void QuickSort::goQuickSort(){
    QuckSort(data,0,length);
    finishedSignal();
}
