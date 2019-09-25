#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    int depth;  //路径的深度
    int *path;  //走过的城市
    int pathWeight; //路径的权重
    int *visited;  //已经参观了的城市 用（0,1）标记
    Node *sons; //孩子节点
};

#endif // NODE_H
