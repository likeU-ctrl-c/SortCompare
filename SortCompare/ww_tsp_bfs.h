#ifndef WW_TSP_BFS_H
#define WW_TSP_BFS_H

#include <QObject>
#include<node.h>
#include<map.h>

class WW_TSP_BFS : public QObject
{
    Q_OBJECT
public:
    explicit WW_TSP_BFS(QObject *parent = nullptr);
     explicit WW_TSP_BFS(int cityNum,int* &OPTpath,int *cityX,int *cityY,int max=100,int min=1,QObject *parent = nullptr);
    int n;
    int minWeight=999999;
    int **map=nullptr;
    int *optPath=nullptr;
    int nodeNum=0;//记录节点数；


    void dfs(Node curnode);
    void godfs();
signals:
    void dfsSignal(int curMinWeight,int nodeNum);
    void finished();
public slots:
};

#endif // WW_TSP_BFS_H
