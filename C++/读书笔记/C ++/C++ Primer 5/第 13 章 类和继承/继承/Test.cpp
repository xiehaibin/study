#include "Minbox.h"
#include <iostream>
using namespace std;


int main(void)
{
	//Cbox box1(10, 5, 2);
	//Cbox box2;    
	//Cbox box3;          // Cbox box3; ����д��Cbox box3()������ʽ(�����ṩֵ) ����������       

    //box3 = box2 = box1;
	//cout<< box3.GetV() <<endl;
	//box3 = box2 + box1;
	//cout<<"..."<< box3.GetV() <<endl;



	Minbox box("xie hia bin", 1, 1, 1);  
	Minbox b1("xie hia", 2, 2, 2);
	Minbox b2;
    
	cout<< (box+b1).GetV() <<endl; // ��ʹ�����ܼ̳����� ���ص�+ ���ڲ�ֻ�����㸸�������
	return 0; 
}
