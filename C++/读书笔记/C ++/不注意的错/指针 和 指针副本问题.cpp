#include <iostream>
#include <cstring>
using namespace std;

extern "C" { void fun(char ch1[], char *pstr); }

int main(void)
{
	char ch1[15] = "xie hai bin";
	char *pstr   = "c";             // char *pstr

	cout<< &pstr <<" : "<<*pstr <<endl; 

    fun(ch1, pstr);

	if (pstr == NULL)                 // pstr NULL
		cout<<"##############"<<endl;
	else
	    cout<< pstr <<endl;   

	return 0;
}
void fun(char ch1[], char *pstr)    
{
	cout<< &pstr <<" : "<< pstr <<endl;
	pstr = new char[strlen(ch1)+1];
    	strcpy(pstr, ch1);

	cout<< pstr <<endl;
}

/*
*  fun(ch1, pstr) 调用 void fun(char ch1[], char *pstr) pstr将差新一个副本
*  这个副本也将指向“c” 但 new char[strlen(ch1)+1]; 函数中的 pstr 指向了刚
*  NOW 出来的哪快内存 而main 函数中的 pstr 还将指向 "c"
*/
