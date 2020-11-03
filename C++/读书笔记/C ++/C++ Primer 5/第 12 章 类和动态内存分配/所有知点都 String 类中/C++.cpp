#include "CString.h"

int main(void)
{
	CString str1 = "xie hia bing";
    CString str2 = "tian xie di yi";

    CString s1;
	CString s2;
	s1 = str1;
    s2 = str2;

	if (s1 == s2)
	{
		cout<<"s1 = s2" <<endl;
	}

	if (s1 > s2)
	{
		cout<<"s1 > s2" <<endl;
	}

	if (s1 < s2)
	{
		cout<<"s1 < s2" <<endl;
	}


	if ("xie hia bing" == str1)
	{
		cout<<"xie hai bin == s1"<<endl;
	}

	cout<< str1[2] <<endl;

    str1[2] = 'X';

	cout<< CString::GetAmout() <<endl;

	cout<< str1 << str2 <<endl;

	cin>>str1;

	cout<< str1 <<endl;

	for(int i = 0; i < str1.GetSize(); i++)
		cout<< str1[i] <<" ";

	return 0;
}