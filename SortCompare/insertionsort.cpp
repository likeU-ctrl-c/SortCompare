#include "insertionsort.h"


InsertionSort::InsertionSort(int l,int md,int *array,QObject *parent ) : QObject(parent)
{
    this->length=l;
    this->mDelay=md;
    this->data=array;

}

void InsertionSort::goInsertionSort(){
    int key;
    for (int i=1;i<length;i++) {

        key=data[i];
        int j=i-1;
        while(j>=0&&data[j]>=key){
            data[j+1]=data[j];
            j=j-1;
            insertionSignal(i,j,key);
            QThread::msleep(static_cast<unsigned long>(mDelay));
        }

        data[j+1]=key;
//        insertionSignal(i,j);
//        QThread::msleep(static_cast<unsigned long>(mDelay));

    }
    for(int i=0;i<length;i++){
        insertionSignal(i,i,i);
       QThread::msleep((static_cast<unsigned int>(mDelay)));
    }
    finishedSignal();
}
