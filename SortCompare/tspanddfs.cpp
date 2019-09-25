#include "tspanddfs.h"
#include "ui_tspanddfs.h"
#include"tspdialog.h"
#include<QPainter>
#include<QColor>
#include<time.h>
#include<qdebug.h>
#include<QDebug>
#include<QMessageBox>

TSPandDFS::TSPandDFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TSPandDFS)
{
    ui->setupUi(this);
    width=this->frameGeometry().width()-20;
    height=this->frameGeometry().height()-20;
     qDebug()<<"初始化cityX";
    if(cityX==nullptr){
        cityX=new int[cityNum+1];
    }else {
        delete [] cityX;
        cityX=nullptr;
        cityX=new int[cityNum+1];
    }
     qDebug()<<"初始化cityY";
    if(cityY==nullptr){
        cityY=new int[cityNum+1];
    }else {
        delete [] cityY;
        cityY=nullptr;
        cityY=new int[cityNum+1];
    }
    for(int i=0;i<cityNum+1;i++){
        cityX[i]=qrand()%width;
        cityY[i]=qrand()%height+50;
        if(cityX[i]>width-20)cityX[i]=width-20;
        if(cityY[i]>=height-20)cityY[i]=height-20;
    }
 qDebug()<<"初始化OPTpath";
    if(OPTpath==nullptr){
        OPTpath=new int[cityNum+2];
    }else {
        delete [] OPTpath;
        OPTpath=nullptr;
        OPTpath=new int[cityNum+2];
    }
    OPTpath[0]=0;
    OPTpath[cityNum+1]=0;
    for(int i=1;i<cityNum+1;i++){
        OPTpath[i]=i;
        qDebug()<<"初始化OPTpath的值["<<i<<"]="<<OPTpath[i];
    }
}

TSPandDFS::~TSPandDFS()
{
//    delete [] OPTpath;
//    delete [] cityX;
//    delete [] cityY;
//    delete  dfs;


    qthread->exit(0);


    delete ui;
}
//弹出修改对话框
void TSPandDFS::on_pushButton_clicked()
{
//    flag=false;
    TSPDialog  *tspdialog = new TSPDialog;
    tspdialog->setModal(true);
    tspdialog->setAttribute(Qt::WA_ShowModal, true);
    tspdialog->setWindowModality(Qt::ApplicationModal);
    tspdialog->show();
    connect(tspdialog,&TSPDialog::receive,this,&TSPandDFS::updateData);

}
//修改配置对应的函数
void TSPandDFS::updateData(int cityNum,int max,int min){

    qDebug()<<"这是修改配置的函数返回城市的数量："<<cityNum<<endl;
    this->cityNum=cityNum;
    this->max=max;
    this->min=min;
    if(cityX!=nullptr){
       delete [] cityX;
        cityX=nullptr;
    }
    if(cityY!=nullptr){
       delete [] cityY;
        cityY=nullptr;
    }
    if(OPTpath!=nullptr){
        delete [] OPTpath;
        OPTpath=nullptr;
    }
        OPTpath = new int[cityNum+2];
        OPTpath[0]=0;
        OPTpath[cityNum+1]=0;
        for(int i=1;i<cityNum+1;i++){
            OPTpath[i]=i;
        }
        width=this->frameGeometry().width();
        height=this->frameGeometry().height();
        cityX=new int[cityNum+1];
        cityY=new int[cityNum+1];
        for(int i=0;i<cityNum+1;i++){
            cityX[i]=qrand()%width;
            cityY[i]=qrand()%height+50;
            if(cityX[i]>width-20)cityX[i]=width-20;
            if(cityY[i]>=height-20)cityY[i]=height-20;
        }
        repaint();
}
//点击运行深度优先搜索
void TSPandDFS::on_pushButton_2_clicked()
{
    type=1;
    dfs = new DFS(cityNum,OPTpath,cityX,cityY);
    qDebug()<<"dfs的指针是空的了"<<dfs<<endl;
    for(int i=0;i<cityNum+2;i++){
         qDebug()<<"运行dfs算法时的OPTpath【："<<i<<"】="<<OPTpath[i]<<endl;
    }
     qDebug()<<"运行dfs算法时的线程1"<<endl;
     connect(dfs,&DFS::dfsSignal,this,&TSPandDFS::dfsDeal);
      qDebug()<<"运行dfs算法时的线程2"<<endl;
     connect(this,&TSPandDFS::start,dfs,&DFS::goDepthFirstSearch);
      qDebug()<<"运行dfs算法时的线程3"<<endl;
     connect(dfs,&DFS::finished,this,&TSPandDFS::dfsFinishDeal);
      qDebug()<<"运行dfs算法时的线程4"<<endl;
     qthread=new QThread;
      qDebug()<<"运行dfs算法时的线程5"<<endl;
     dfs->moveToThread(qthread);
      qDebug()<<"运行dfs算法时的线程6"<<endl;

     qthread->start();
      qDebug()<<"运行dfs算法时的线程7"<<endl;
     emit start();
       qDebug()<<"运行dfs算法时的线程8"<<endl;
    //==========================2222===============================
//    WW_TSP_BFS *dfs2 = new WW_TSP_BFS(cityNum,OPTpath,cityX,cityY);

//         connect(dfs2,&WW_TSP_BFS::dfsSignal,this,&TSPandDFS::dfsDeal);
//         connect(this,&TSPandDFS::start,dfs2,&WW_TSP_BFS::godfs);
//         connect(dfs2,&WW_TSP_BFS::finished,this,&TSPandDFS::dfsFinishDeal);
//         qthread=new QThread;
//         dfs2->moveToThread(qthread);
//         qthread->start();
//         emit start();


}
//画图事件
void TSPandDFS::paintEvent(QPaintEvent *){

   //定义一个画家
   QPainter painter(this);
    //指定画笔
    QPen pen(QColor(255,0,0));
    //让画家拿起画笔
    painter.setPen(pen);
    //画城市
    for(int i=0;i<cityNum+1;i++){
        pen.setColor(QColor(255,0,0));
        painter.setPen(pen);
       painter.drawEllipse(cityX[i],cityY[i],20,20);
       pen.setColor(Qt::black);
       painter.setPen(pen);
       painter.drawText(cityX[i]+10,cityY[i]+10,QString::number(i));
    }

    pen.setColor(Qt::green);
    //画路径
    for(int i=0;i<cityNum+1;i++){
        int city1=OPTpath[i];
        int city2=OPTpath[i+1];
         painter.setPen(pen);
       painter.drawLine(cityX[city1]+10,cityY[city1]+10,cityX[city2]+10,cityY[city2]+10);
    }


}

void TSPandDFS::dfsDeal(int curMinWidth,int nodeNum){
    repaint();
    ui->lineEdit->setText(QString::number(curMinWidth));
    ui->lineEdit_2->setText(QString::number(nodeNum));

}

void TSPandDFS::dfsFinishDeal(){
    if(type==1){
        type=0;
        qthread=new QThread;
        delete dfs;
    }else if(type==2){
        type=0;
        qthread=new QThread;
        delete tspbb;
    }

    QString rouse;
    for(int i=0;i<cityNum+2;i++){
        rouse+=QString::number(OPTpath[i]);
        rouse+="  ";
    }
    QMessageBox::about(this, "结果",rouse);


}

void TSPandDFS::on_pushButton_3_clicked()
{
    type=2;
    tspbb=new TSPAndBBAlgorithm(cityNum,OPTpath,cityX,cityY,max,min);

    connect(tspbb,&TSPAndBBAlgorithm::dfsSignal,this,&TSPandDFS::dfsDeal);
    connect(this,&TSPandDFS::startBB,tspbb,&TSPAndBBAlgorithm::goDepthFirstSearch);
    connect(tspbb,&TSPAndBBAlgorithm::finished,this,&TSPandDFS::dfsFinishDeal);
        qDebug()<<"剪枝算法中的线程指针是空的了"<<tspbb<<endl;
        qthread=new QThread;
        tspbb->moveToThread(qthread);
        qthread->start();
        emit startBB();


}
