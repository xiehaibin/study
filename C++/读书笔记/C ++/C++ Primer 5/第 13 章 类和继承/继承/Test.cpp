#include "Minbox.h"
#include <iostream>
using namespace std;


int main(void)
{
	//Cbox box1(10, 5, 2);
	//Cbox box2;    
	//Cbox box3;          // Cbox box3; 不能写成Cbox box3()此种形式(必须提供值) 否则编绎出错       

    //box3 = box2 = box1;
	//cout<< box3.GetV() <<endl;
	//box3 = box2 + box1;
	//cout<<"..."<< box3.GetV() <<endl;



	Minbox box("xie hia bin", 1, 1, 1);  
	Minbox b1("xie hia", 2, 2, 2);
	Minbox b2;
    
	cout<< (box+b1).GetV() <<endl; // 即使子类能继承下来 重载的+ 但内部只能运算父类的数据
	return 0; 
}
