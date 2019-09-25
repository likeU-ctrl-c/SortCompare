#include "countingsort.h"

CountingSort::CountingSort(QObject *parent) : QObject(parent)
{

}
CountingSort::CountingSort(int l,int max,int md,int *array,QObject *parent) : QObject(parent)
{
    length=l;
    mDelay=md;
    this->max=max;
    this->data=array;
}
void CountingSort::countingSort(int *a,int length){
        int *c = new int [max];
        int *b = new int[length];
        for(int i=0;i<max;i++){
            c[i]=0;
        }

        for(int j=0;j<length;j++){
            c[a[j]]=c[a[j]]+1;
        }

        for(int i=1;i<max;i++){
            c[i]=c[i]+c[i-1];
        }

        for(int j=length-1;j>=0;j--){
            b[c[a[j]]-1]=a[j];
            c[a[j]]=c[a[j]]-1;
        }
        for(int i=0;i<length;i++){
            a[i]=b[i];
            countingSignal(i);
            QThread::msleep(static_cast<unsigned int>(mDelay));
        }
        delete [] b;
        delete []c;

}

void CountingSort::goCountingSort(){
    countingSort(data,length);
    finishedSignal();
}
