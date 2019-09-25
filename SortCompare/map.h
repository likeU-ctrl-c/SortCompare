#ifndef MAP_H
#define MAP_H

#include <QObject>
#include<QFile>

class Map : public QObject
{
    Q_OBJECT
public:
    explicit Map(QObject *parent = nullptr);
    explicit Map(int cityNum,int max=100,int min=1,QObject *parent = nullptr);
    QString path;
    int cityNum;
    int max=100;
    int min=1;
    int **map=nullptr;

    void creatMap();
    void getMap(int *cityX,int *cityY);

signals:

public slots:
};

#endif // MAP_H
