//---------------- head.txt---------------
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
//-------------------- 
//------------------------------
/*
�û�����ŵĴ��� 
*/
//-----------------------------------
//--------------------codeState.txt----------------
const int MAX_NUM = 100;
const char* path="D:\\test.txt";
const char* errLog="d:\\errLog.txt";
//---------------------------------------

//------------------------------------------MustCode.txt
int a[MAX_NUM]; //����ļ��ж��������
int total = 0;  //�������������
void getArray(){
	 int total = 0;//�������������
	 ifstream srcFile;
   	 srcFile.open(path); //���ı�ģʽ�������ļ� ���� 
   	 ofstream errFile(errLog,ios::out); //���ı�ģʽ�򿪴�����־�ļ� ��д
    if(!srcFile) { //��ʧ��
        errFile << "error opening source file." << endl;
        srcFile.close();
    }
    if(!errFile){//������־�ļ��򿪳��� 
    	 errFile << "error opening errlog file." << endl;
	}
    int x;   
    while(srcFile >> x) //��������cin������ifstream����
        a[total++] = x;
    srcFile.close();
    errFile.close();   
}
//---------------------------------------------
//---------------------------------------UseUserCode.txt
void sort(int *array,int length){
/*
�û������㷨����
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
