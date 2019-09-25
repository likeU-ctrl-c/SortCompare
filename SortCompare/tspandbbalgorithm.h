#ifndef TSPANDBBALGORITHM_H
#define TSPANDBBALGORITHM_H


#include <QObject>
#include"node.h"
#include"map.h"

class TSPAndBBAlgorithm : public QObject
{
    Q_OBJECT
public:
    explicit TSPAndBBAlgorithm(QObject *parent = nullptr);
    explicit TSPAndBBAlgorithm(int cityNum,int* OPTpath,int *cityX,int *cityY,int max=100,int min=1,QObject *parent = nullptr);
    int n;
    int *a=nullptr;
    int *b=nullptr;
    int minWeight=999999;
    int **map=nullptr;
    int *OPTpath=nullptr;
    int nodeNum=0;//记录节点数；
    void cpArray(int *a,int *b,int size);
    void calculateWeight(Node &curNode);
    void DepthFirstSearch(Node &curNode);
    void outputOPT();
    void goDepthFirstSearch();
signals:
        void dfsSignal(int curMinWeight,int nodeNum);
        void finished();

public slots:
};

#endif // TSPANDBBALGORITHM_H
