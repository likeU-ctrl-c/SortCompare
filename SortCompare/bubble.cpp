#include "bubble.h"


Bubble::Bubble(int l, int m, int mD, int *data, QObject *parent) : QObject(parent)
{
    qsrand(static_cast<uint>(QTime::currentTime().msec())); //初始化随机种子
    length = l;
    max = m;
    mDelay = mD;
    this->data = data;

}
void Bubble::goBubble()
{


    for(int i = 1; i < length ; i ++){

        for(int j = 0; j < length-i; j++){
            if(data[j] > data[j+1]){
                int t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;

            }
            emit bubbleSignal(j);
             QThread::msleep(static_cast<unsigned int>(mDelay));

        }

    }
    for(int i = 0; i < length; i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}
