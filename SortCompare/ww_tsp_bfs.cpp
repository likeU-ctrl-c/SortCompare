#include "ww_tsp_bfs.h"
#include<QDebug>

WW_TSP_BFS::WW_TSP_BFS(QObject *parent) : QObject(parent)
{

}
WW_TSP_BFS::WW_TSP_BFS(int cityNum,int* &OPTpath,int *cityX,int *cityY,int max,int min,QObject *parent) : QObject(parent)
{
    this->n=cityNum;
    //初始化解的值
    if(this->optPath!=nullptr){
        delete [] this->optPath;
        this->optPath=nullptr;
    }
        this->optPath=OPTpath;


    //初始化地图

    Map *map2=new Map(cityNum,max,min);

    map2->getMap(cityX,cityY);

    this->map=map2->map;
}

void WW_TSP_BFS::dfs(Node curnode){
    if (curnode.depth == n-1 )
    {
        qDebug()<<"1";
        nodeNum++;
        if (map[curnode.path[curnode.depth]][0] == 0 || curnode.pathWeight>minWeight)
        {
              qDebug()<<"2";
            return;
        }
        curnode.visited[n] = 1;
        curnode.pathWeight += map[curnode.path[curnode.depth]][0];
        if (curnode.pathWeight < minWeight)
        {
              qDebug()<<"3";
            minWeight = curnode.pathWeight;
            optPath = curnode.path;
            dfsSignal(minWeight,nodeNum);
        }

        return;
    }
    for (int i = 0; i < n ; ++i)
    {

            if (curnode.visited[i] == 0 && map[curnode.path[curnode.depth]][i] != 0 )//还有节点未被访问过
            {  qDebug()<<"3";
                Node *next = (Node *)new Node();
                next->depth = curnode.depth + 1;
                next->path = new int[n+1];
                next->visited = new int[n+1];
                  qDebug()<<"4";
                for (int k = 0; k < n+1; ++k)
                {
                    next->path[k] = curnode.path[k];
                    next->visited[k] = curnode.visited[k];
                }
                  qDebug()<<"5";
                next->pathWeight =curnode.pathWeight + map[curnode.path[curnode.depth]][i];
                next->visited[i] = 1;
                next->path[next->depth] = i;
                curnode.sons = next;
                  qDebug()<<"6";
                if (next->pathWeight <= minWeight)
                {
                      qDebug()<<"8";
                    dfs(*(curnode.sons));
                      qDebug()<<"9";
                }
                  qDebug()<<"7   "<<i;
            }

    }
}
void WW_TSP_BFS::godfs(){
    Node root;
        root.depth = 0;
        root.pathWeight = 0;
        root.path = new int[n+1];//初始化为0
        for (int i = 0; i < n+1; ++i)
        {
            root.path[i] = 0;
        }
        root.visited = new int[n+1];
        for (int i = 0; i < n+1; ++i)
        {
            root.visited[i] = 0;
        }
        root.visited[0] = 1;
        dfs(root);
        finished();
}
