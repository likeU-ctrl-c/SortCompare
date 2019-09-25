#include "sortshow.h"
#include "ui_sortshow.h"
#include<QFile>
#include<QPainter>
#include<QMessageBox>
#include<QTextStream>
#include<QProcess>
#include<composefile.h>
#include<QThread>
#include<QtMath>
#include<QDebug>

SortShow::SortShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortShow)
{
        ui->setupUi(this);
    ComposeFile cf ;
    arrayMax=cf.max;
    cf.makeRandomArray(100);
     readArrayFromFile();
     QVector2Arrat();
      thread=new QThread();

//            //=======================插入排序=============================
                insertionSort=new InsertionSort(size,5,array);
                //进行信号与槽的绑定
                connect(insertionSort,&InsertionSort::insertionSignal,this,&SortShow::insertionDeal);
                connect(this,&SortShow::startInsertion,insertionSort,&InsertionSort::goInsertionSort);
                connect(insertionSort,&InsertionSort::finishedSignal,this,&SortShow::finishedDeal);
//             insertionSort->moveToThread(thread);



            //===========================归并排序=========================
                 merge=new MergeSort(size,5,array);
                //进行信号与槽的绑定
                connect(merge,&MergeSort::mergeSignal,this,&SortShow::deal);
                connect(this,&SortShow::startMerge,merge,&MergeSort::goMERGESort);
                connect(merge,&MergeSort::finishedSignal,this,&SortShow::finishedDeal);
//                 merge->moveToThread(thread);

            //============================快速排序================
                quick=new QuickSort(size,5,array);
                //进行信号与槽的绑定
                connect(quick,&QuickSort::quickSignal,this,&SortShow::deal);
                connect(this,&SortShow::startQuick,quick,&QuickSort::goQuickSort);
                connect(quick,&QuickSort::finishedSignal,this,&SortShow::finishedDeal);


            //====================堆排序==========================
                heap=new HeapSort(size,5,array);
                    //进行信号与槽的绑定
                 connect(heap,&HeapSort::heapSignal,this,&SortShow::deal);
                 connect(this,&SortShow::startHeap,heap,&HeapSort::goHeapSort);
                 connect(heap,&HeapSort::finishedSignal,this,&SortShow::finishedDeal);


            //==========================计数排序===================
                     counting=new CountingSort(size,arrayMax,5,array);
                 //进行信号与槽的绑定
                connect(counting,&CountingSort::countingSignal,this,&SortShow::deal);
                connect(this,&SortShow::startCounting,counting,&CountingSort::goCountingSort);
                connect(counting,&CountingSort::finishedSignal,this,&SortShow::finishedDeal);

            //==========================基数排序===================
                  radixSort=new RadixSort(size,arrayMax,5,array);
                 //进行信号与槽的绑定
                connect(radixSort,&RadixSort::radixSignal,this,&SortShow::deal);
                connect(this,&SortShow::startRadix,radixSort,&RadixSort::goRadixSort);
                 connect(radixSort,&RadixSort::finishedSignal,this,&SortShow::finishedDeal);


//                    thread->start(); //开启子线程
//                    emit start();  //运行子线程的算法函数

}



SortShow::~SortShow()
{
    delete [] array;
thread->quit();  //结束子线程
    thread->wait();  //回收子线程资源

    delete ui;
}

//绘图事件
void SortShow::paintEvent(QPaintEvent *){
     //得到窗口的大小
  width=this->frameGeometry().width();
  height=this->frameGeometry().height();
  int times=qFloor(height/arrayMax);
    int recWidth=width/size;
    //定义一个画家
    QPainter painter(this);
//    //指定画笔
//    QPen pen(QColor(255,0,0));
//    //让画家拿起画笔
//    painter.setPen(pen);

    //画刷填充颜色
    QBrush brush(Qt::red);
    //让画家拿起画刷
    painter.setBrush(brush);

    for(int i=0;i<size;i++){
//         painter.drawText(i*recWidth+recWidth/2,height,QString::number(i));
        qDebug()<<"sortId ==== "<<sortId;
        if(sortId==1){
            if(i==curi&&curi!=curj){
                //画刷填充颜色
              brush.setColor(Qt::black);
              //让画家拿起画刷
              painter.setBrush(brush);
               painter.drawRect(i*recWidth+1,height-10-array[i]*times,recWidth,array[i]*times);
            }else if(i==curj||curi==curj){
                brush.setColor(Qt::green);
                //让画家拿起画刷
                painter.setBrush(brush);
                if(curi==curj){
                     painter.drawRect(i*recWidth+1,height-10-array[i]*times,recWidth,array[i]*times);
                }else{
                     painter.drawRect(i*recWidth+1,height-10-key*times,recWidth,key*times);
                }
            }
            else{
                brush.setColor(Qt::red);
                //让画家拿起画刷
                painter.setBrush(brush);
                 painter.drawRect(i*recWidth+1,height-10-array[i]*times,recWidth,array[i]*times);
            }
        }else {
            if(i==cur){
                //画刷填充颜色
                brush.setColor(Qt::green);
                //让画家拿起画刷
                painter.setBrush(brush);
                 painter.drawRect(i*recWidth+1,height-10-array[i]*times,recWidth,array[i]*times);
            }else{
                //画刷填充颜色
                brush.setColor(Qt::red);
                //让画家拿起画刷
                painter.setBrush(brush);

                painter.drawRect(i*recWidth+1,height-10-array[i]*times,recWidth,array[i]*times);
            }
        }


}

}

void SortShow::readArrayFromFile(){
      QFile file("D:\\test.txt");
//      file.open(QIODevice::ReadOnly  | QIODevice::Text);
      if (!file.open(QIODevice::ReadOnly|QIODevice::Text))//打开指定文件
          {
              QMessageBox::about(this, "文件", "文件打开失败");
          }else {
              QTextStream txtInput(&file);
              QString lineStr;
              while (!txtInput.atEnd())
              {
                  lineStr = txtInput.readLine();  //读取数据

                  intArray.push_back(lineStr.toInt());

//                  QMessageBox::about(this, "字段数据", lineStr);

              }
           }
      file.close();

}


void SortShow::QVector2Arrat(){
    int length=intArray.length();
    size=length;
    int* a=new int[length];
    for(int i=0;i<length;i++){
        a[i]=intArray[i];
    }
    array=a;
}
void SortShow::deal(int c){
    cur =c;
    repaint();//进行重绘
}
void SortShow::insertionDeal(int curi,int curj,int key){

    this->curi=curi;
    this->curj=curj;
    this->key=key;
//      QMessageBox::about(this, "字段数据", QString::number(curi));
//        QMessageBox::about(this, "字段数据", QString::number(curj));
    repaint();//进行重绘
}


//播放动画


void SortShow::playSort(){

   qDebug()<<"sortId="<<sortId;

    if(sortId==1){
        qDebug()<<"插入排序="<<sortId;
        //=======================插入排序=============================
         thread->exit();
       insertionSort->moveToThread(thread);
       thread->start(); //开启子线程
       emit startInsertion();  //运行子线程的算法函数

    }else if (sortId==2) {
        //===========================归并排序=========================
 thread->exit();
       merge->moveToThread(thread);
       thread->start(); //开启子线程
       emit startMerge();  //运行子线程的算法函数

   }else if (sortId==3) {
        //============================快速排序================
         thread->exit();
           quick->moveToThread(thread);
           thread->start(); //开启子线程
           emit startQuick();  //运行子线程的算法函数

    }else if (sortId==4) {

        //====================堆排序==========================
         thread->exit();
               heap->moveToThread(thread);
               thread->start(); //开启子线程
               emit startHeap();  //运行子线程的算法函数


    }else if (sortId==5) {
        //==========================计数排序===================
         thread->exit();
           counting->moveToThread(thread);
           thread->start(); //开启子线程
           emit startCounting();  //运行子线程的算法函数

    }else if (sortId==6) {
        //==========================基数排序===================
          thread->exit();
          radixSort->moveToThread(thread);
          thread->start(); //开启子线程
          emit startRadix();  //运行子线程的算法函数

    }

    //=============================冒泡排序=========================
//     bubble=new Bubble(100,100,5,array);
//          //进行信号与槽的绑定
//      connect(bubble,&Bubble::bubbleSignal,this,&SortShow::deal);
//      connect(this,&SortShow::start,bubble,&Bubble::goBubble);
//     bubble->moveToThread(thread);



}











//处理来自主页的点击的哪个排序算法的槽函数

void SortShow::showWhichSort(int num){
    sortId=num;
    playSort();
}


//处理排序算法结束后的槽函数
void SortShow::finishedDeal(){
//    delete [] array;
//    thread->quit();  //结束子线程
//    thread->wait();  //回收子线程资源
     QMessageBox::about(this, "排序完成","排序完成!");
}
