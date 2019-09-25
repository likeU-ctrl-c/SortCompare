//---------------- head.txt---------------
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
//-------------------- 
//------------------------------
/*
用户代码放的代码 
*/
//-----------------------------------
//--------------------codeState.txt----------------
const int MAX_NUM = 100;
const char* path="D:\\test.txt";
const char* errLog="d:\\errLog.txt";
//---------------------------------------

//------------------------------------------MustCode.txt
int a[MAX_NUM]; //存放文件中读入的整数
int total = 0;  //读入的整数个数
void getArray(){
	 int total = 0;//读入的整数个数
	 ifstream srcFile;
   	 srcFile.open(path); //以文本模式打开数据文件 备读 
   	 ofstream errFile(errLog,ios::out); //以文本模式打开错误日志文件 备写
    if(!srcFile) { //打开失败
        errFile << "error opening source file." << endl;
        srcFile.close();
    }
    if(!errFile){//错误日志文件打开出错 
    	 errFile << "error opening errlog file." << endl;
	}
    int x;   
    while(srcFile >> x) //可以像用cin那样用ifstream对象
        a[total++] = x;
    srcFile.close();
    errFile.close();   
}
//---------------------------------------------
//---------------------------------------UseUserCode.txt
void sort(int *array,int length){
/*
用户排序算法调用
quickSort(arry,length);
*/
}
//---------------------
//--------------------mian.txt
int main()
{
  getArray();
  sort(a,MAX_NUM);
   return 0;
}
