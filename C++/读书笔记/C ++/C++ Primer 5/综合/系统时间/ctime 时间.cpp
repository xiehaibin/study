//******************************************
//* ���ƣ� ʹ��time��ʱ                    *  
//* ���ܣ�                                 *
//* ����                                 *
//* ʱ�䣺 2010.06.22  09��17              *
//******************************************
#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int secs = 0;
	cin>>secs;

   //CLK_TCK   //ϵͳ��#define CLK_TCK  CLOCKS_PER_SEC ÿ���Ӱ�����ϵͳʱ�䵥λ��
   clock_t daly= secs * CLOCKS_PER_SEC; // clock_tϵͳʱ��ı��� ������ unsigned long \ long ...
  // secs / CLOCKS_PER_SEC ���õ�����
   cout<<"start....."<<endl; 
   cout<< clock() <<endl;
   clock_t start = clock();
   while((clock() - start) < daly);
   cout<<"End......."<<endl;
	return 0;
}