#include "map.h"
#include<QTextStream>
#include<time.h>
#include<QtDebug>
Map::Map(QObject *parent) : QObject(parent)
{

}
Map::Map(int cityNum,int max,int min,QObject *parent) : QObject(parent)
{
    this->cityNum=cityNum;
    this->max=max;
    this->min=min;
}
void Map::creatMap(){
    int **map= (int**)new int [cityNum+1];
    qsrand(time(NULL));
     QFile f(path);
    *map=new int[cityNum+1];
        for(int i=0; i<cityNum+1; i++) {
            map[i]=new int[cityNum+1];
        }
        //将二维数组的值写入
        for(int i=0; i<cityNum+1; i++) {
            for(int j=i; j<cityNum+1; j++) {
                int a=qrand()%max+min;;
                if(i==j) {
                    map[i][j]=0;
                } else {
                    map[i][j]=a;
                    map[j][i]=a;
                }
            }
        }
        for(int j=0; j<cityNum+1; j++) {
            for(int i=0; i<cityNum+1; i++) {
                QString num=QString::number(map[j][i],10)+ " ";
                //写入文件
                f.write(num.toUtf8());
            }
            f.write(" \n");
        }
     f.close();
}
void Map::getMap(int *cityX,int *cityY){
     qDebug()<<"初始化地图之前1："<<endl;
     if(this->map!=nullptr){
         delete [] this->map;
         this->map=nullptr;
     }
    map= (int**)new int *[cityNum+1];
     qDebug()<<"初始化地图之前2："<<endl;
    qsrand(time(NULL));
 qDebug()<<"初始化法地图之前3："<<endl;
        for(int i=0; i<cityNum+1; i++) {
             map[i]=new int[cityNum];
        }
         qDebug()<<"地图之前4："<<endl;
        //将二维数组的值写入
        for(int i=0; i<cityNum+1; i++) {
            for(int j=i; j<cityNum+1; j++) {
                int a=int((cityX[j]-cityX[i])*(cityX[j]-cityX[i]))+int((cityY[j]-cityY[i])*(cityY[j]-cityY[i]));
                if(i==j) {
                     qDebug()<<"地图之前41111："<<endl;
                    map[i][j]=0;
                } else {
                     qDebug()<<"地图之前422222："<<endl;
                    map[i][j]=a;
                     qDebug()<<"地图之前433333："<<endl;
                    map[j][i]=map[i][j];
                     qDebug()<<"地图之前4444444："<<endl;
                }
            }
        }
 qDebug()<<"地图之前5："<<endl;
//        for(int i=0; i<cityNum+1; i++) {
//            for(int j=i; j<cityNum+1; j++) {
//                if(i==j) {
//                    map[i][j]=0;
//                } else {
//                    map[j][i]=map[i][j];
//                }
//            }
//        }
}




