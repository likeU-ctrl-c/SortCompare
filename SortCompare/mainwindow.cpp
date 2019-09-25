#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QPushButton>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>
#include<QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    setWindowTitle("主窗口");
    this->resize(600,400);
    //菜单栏 只有一个
   QMenuBar *bar= menuBar();
   //将菜单栏设置到窗口中
   setMenuBar(bar);

   //设置菜单
   QMenu *fileMenu = bar->addMenu("菜单");
   QMenu *allSortShow=bar->addMenu("演示排序算法");
   QMenu *problem = bar->addMenu("算法问题");

   //添加菜单项
   QAction *newAction = fileMenu->addAction("自己写代码");
   QAction *newAction2 = fileMenu->addAction("实现排序算法");

    //添加分割线
   fileMenu->addSeparator();
//   QAction *sortShow=fileMenu->addAction("排序算法展示");

   //给排序算法写菜单
   QAction *insetionSort = allSortShow->addAction("插入排序");
   allSortShow->addSeparator();
   QAction *mergeSort = allSortShow->addAction("归并排序");
   allSortShow->addSeparator();
   QAction *quickSort = allSortShow->addAction("快速排序");
   allSortShow->addSeparator();
   QAction *heapSort = allSortShow->addAction("堆排序");
   allSortShow->addSeparator();
   QAction *CountingSort = allSortShow->addAction("计数排序");
    allSortShow->addSeparator();
    QAction *radixSort = allSortShow->addAction("基数排序");

//算法问题添加菜单
    QAction *tsp= problem->addAction("旅行商问题TSP");






   //工具栏
   QToolBar *toolBar=new QToolBar(this);
   //将工具栏放入到窗口中
   addToolBar(Qt::TopToolBarArea,toolBar);

    //只允许上下情况停靠。
   toolBar->setAllowedAreas(Qt::TopToolBarArea|Qt::BottomToolBarArea|Qt::LeftToolBarArea|Qt::RightToolBarArea);

   //设置浮动
   toolBar->setFloatable(false);
   //设置移动（总开关)
   toolBar->setMovable(false);

   //工具栏中添加菜单项
   toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(newAction2);
    toolBar->addAction(tsp);
   //添加分割线
   toolBar->addSeparator();
//   toolBar->addAction(sortShow);


    connect(newAction,SIGNAL(triggered()),this,SLOT(loadUserCode()));
    connect(newAction2,SIGNAL(triggered()),this,SLOT(loadWriteCode()));
//    connect(sortShow,SIGNAL(triggered()),this,SLOT(sortShow()));

//旅行商问题的窗口显示
 connect(tsp,SIGNAL(triggered()),this,SLOT(tspShow()));


    //==============排序按钮与窗口链接==============
    connect(insetionSort,SIGNAL(triggered()),this,SLOT(InsertionSortShow()));
    connect(mergeSort,SIGNAL(triggered()),this,SLOT(MergeSortShow()));
    connect(quickSort,SIGNAL(triggered()),this,SLOT(quickSortShow()));
    connect(heapSort,SIGNAL(triggered()),this,SLOT(heapSortShow()));
    connect(CountingSort,SIGNAL(triggered()),this,SLOT(countingSortShow()));
    connect(radixSort,SIGNAL(triggered()),this,SLOT(radixSortShow()));





}

MainWindow::~MainWindow()
{
    delete ui;
}

//显示排序算法的窗口 =================================
void MainWindow::sortPlay(){
   SortShow *sortShow=new SortShow();
   sortShow->setParent(this);
    this->setCentralWidget(sortShow);
    connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
     sortId(0);
}




//显示插入排序的窗口；
void MainWindow::InsertionSortShow(){
//    setCentralWidget(nullptr);
    SortShow *sortShow=new SortShow();
    sortShow->setParent(this);
    this->setCentralWidget(sortShow);
     connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
    emit sortId(1);
}
//显示归并排序的窗口；
void MainWindow::MergeSortShow(){

     SortShow *sortShow=new SortShow();
    sortShow->setParent(this);
    this->setCentralWidget(sortShow);
    connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
     sortId(2);
}
//显示快速排序的窗口；
void MainWindow::quickSortShow(){
     SortShow *sortShow=new SortShow();
    sortShow->setParent(this);
    this->setCentralWidget(sortShow);
    connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
     sortId(3);
}
//显示堆排序的窗口；
void MainWindow::heapSortShow(){
     SortShow *sortShow=new SortShow();
    sortShow->setParent(this);
    this->setCentralWidget(sortShow);
    connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
     sortId(4);
}
//显示计数排序的窗口；
void MainWindow::countingSortShow(){
     SortShow *sortShow=new SortShow();
    sortShow->setParent(this);
    this->setCentralWidget(sortShow);
    connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
     sortId(5);
}
//显示基数排序的窗口；
void MainWindow::radixSortShow(){
     SortShow *sortShow=new SortShow();
    sortShow->setParent(this);
    this->setCentralWidget(sortShow);
    connect(this,&MainWindow::sortId,sortShow,&SortShow::showWhichSort);
     sortId(6);
}


//旅行商窗口显示
void MainWindow::tspShow(){
    TSPandDFS *tsp=new TSPandDFS();
    tsp->setParent(this);
    setCentralWidget(tsp);
}





















//===================================================


//将用户自己写代码的大段空白载入到主页面
void MainWindow::loadUserCode(){
    UserCode *userCode = new UserCode();
    userCode->setParent(this);
    this->setCentralWidget(userCode);
}
//将用户自己排序算法的代码的段载入到主页面
void  MainWindow::loadWriteCode(){

    WriteCode *wc=new WriteCode();
    wc->setParent(this);
    setCentralWidget(wc);
}
//显示主窗口
void MainWindow::receivelogin()
{
    this->show();//显示主窗口
}
void MainWindow::on_pushButton_clicked(){
//    this->hide();
//    emit dlgshow();



}
void MainWindow::on_pushButton_2_clicked(){
    emit quit();
}
