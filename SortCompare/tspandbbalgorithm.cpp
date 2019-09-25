#include "tspandbbalgorithm.h"
#include<QThread>
#include<QDebug>

TSPAndBBAlgorithm::TSPAndBBAlgorithm(QObject *parent): QObject(parent)
{

}
TSPAndBBAlgorithm::TSPAndBBAlgorithm(int cityNum,int* OPTpath,int *cityX,int *cityY,int max,int min,QObject *parent): QObject(parent){
    this->n=cityNum;
    //初始化解的值
    if(this->OPTpath==nullptr){
        this->OPTpath=OPTpath;
    }else {
        delete [] this->OPTpath;
        this->OPTpath=nullptr;
        this->OPTpath=OPTpath;
    }
    //初始化地图
    Map *map2=new Map(cityNum,max,min);
    map2->getMap(cityX,cityY);
    if(this->map==nullptr){
        this->map=map2->map;
    }else {
        delete [] this->map;
        this->map=nullptr;
        this->map=map2->map;
    }
    //初始化a的值
    if(this->a==nullptr){
        this-> a=new int[cityNum+2];
    }else {
        delete [] this->a;
        this->a=nullptr;
        this->a=new int[cityNum+2];
    }
    //初始化b的值
    if(this->b==nullptr){
         this->b=new int[cityNum+1];
    }else {
        delete [] this->b;
        this->b=nullptr;
        this->b=new int[cityNum+1];
    }
    for (int i=0;i<n+2;i++) {
        a[i]=0;
        if(i<n+1){
            b[i]=0;
        }

    }
}
void TSPAndBBAlgorithm::cpArray(int *a,int *b,int size){
    for(int i=0; i<size; i++) {
            a[i]=b[i];
        }
}
void TSPAndBBAlgorithm::calculateWeight(Node &curNode){
    int curNodeWeight=0;
        for(int i=0; i<n+1; i++) {
            int a=curNode.path[i];
            int b=curNode.path[i+1];
            curNodeWeight+=map[a][b];
        }
        curNode.pathWeight=curNodeWeight;
}
void TSPAndBBAlgorithm::DepthFirstSearch(Node &curNode){
    if(curNode.depth==n) {
        nodeNum++;
        calculateWeight(curNode);
        if(curNode.pathWeight<minWeight) {
            minWeight=curNode.pathWeight;
//            OPTpath=curNode.path;
            qDebug()<<"这是在dfs";
            for (int i=0;i<n;i++) {
                OPTpath[i]=curNode.path[i];
                qDebug()<<OPTpath[i];
            }
            dfsSignal(minWeight,nodeNum);
            QThread::msleep(static_cast<int>(5));
        }
    } else {
        curNode.sons = new Node[n-curNode.depth];
        for(int i=0; i<n-curNode.depth; i++) {
            curNode.sons[i].depth=curNode.depth+1;
            curNode.sons[i].path = new int [n+2];
            cpArray(curNode.sons[i].path,curNode.path,n+2);
            curNode.sons[i].visited = new int [n+1];
            cpArray(curNode.sons[i].visited,curNode.visited,n+1);
            int flag =-1;
            for(int j=0; j<n+1; j++) {
                if(curNode.sons[i].visited[j]==0) {
                    flag++;
                }
                if(i==flag) {
                    for(int k=1; k<n+2; k++) {
                        if(curNode.sons[i].path[k]==0) {
                            curNode.sons[i].path[k]=j;
                            int former=curNode.sons[i].path[k-1];
                            int later=curNode.sons[i].path[k];
                            curNode.sons[i].pathWeight=curNode.pathWeight+map[former][later];
                            break;
                        }
                    }
                    curNode.sons[i].visited[j]=1;
                    break;
                }
            }
            if(curNode.sons[i].pathWeight>=minWeight){
                continue;
            }
            DepthFirstSearch(curNode.sons[i]);
        }
    }

}


void TSPAndBBAlgorithm::goDepthFirstSearch(){

    Node root;
    root.depth=0;
    root.path=a;
    root.visited=b;
    DepthFirstSearch(root);
    emit finished();
}
