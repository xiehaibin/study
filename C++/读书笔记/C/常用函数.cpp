#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;

void main(void)
{
//***************** ������ѧ���� *****************
	{
		int i = -123;
		cout<< abs(i) <<endl;       // ��������ֵ  -32768 ����ֵ�� -32768  

		long il = -12345678L;
		cout<< labs(il) <<endl;     // �����;���ֵ                        

		double id = -123.45;        // ʵ�;���ֵ                          *���� math.h*
		cout<< fabs(id) <<endl;

		cout<< ceil(-10.5) <<endl;  // ����/����x����С���� = -10          *���� math.h*
		cout<< ceil(10.9) <<endl;   // = 11

		cout<< floor(-10.5) <<endl; // С��/����X��������� =-11
		cout<< floor(10.9) <<endl;  // =10
	}

// ************* ����ת������ *******************
	{
	   char ch2[10] = "123.45";
	   cout << atof(ch2) <<endl;     // ���ַ���ת���� double             123.45  *���õ����*
	   cout << atoi(ch2) <<endl;     // ���ַ���ת���� int                123     *���õ����*
	   itoa(int, ch[], 10);          // ������ת�����ַ���
    }

// ************ �ַ������� ********************
	{ 
		cout<< isalpha(49) <<endl;   // �ж��Ƿ���Ӣ����ĸ =0                     *���õ����*
		cout<< isalpha('a') <<endl;  // ���Ϊ��0��                               *���õ����*

		cout<< islower(97) <<endl;   // �Ƿ���Ӣ��Сд��ĸ  =���Ϊ��0��          *���õ����*  
		cout<< islower('A') <<endl;  // =0

		cout<< isupper(97) <<endl;   // �Ƿ���Ӣ�Ĵ�д��ĸ  =0
		cout<< isupper('A') <<endl;  // =���Ϊ��0��  

		cout<< isdigit(49) <<endl;   // �Ƿ��������ַ�  =���Ϊ��0��  
		cout<< isdigit('a') <<endl;  // =0

		cout<< tolower(49) <<endl;   // ����д��ĸת����Сд��ĸ =��49
		cout<< tolower('A') <<endl;  // =97

		cout<< toupper('a') <<endl;  // ��Сд��ĸת���ɴ�д��ĸ =65
		cout<< toupper(49) <<endl;   // =49

		cout<< toascii(129) <<endl;  // ���ַ�ת����ASCII����ֵ  =1
		cout<< toascii('a') <<endl;  // =97

	}
// ************ �ַ��������� *********************
	{
	   char a[] = "abcd";
 	   cout<< strupr(a) <<endl;      // ���ַ���Сдת��д =ABCD

	   char b[] = "ABCD";
	   cout<< strlwr(b) <<endl;      // ���ַ�����дתСд =abcd
	}

// *********** �������ú��� ************************
	{
		
	}
}