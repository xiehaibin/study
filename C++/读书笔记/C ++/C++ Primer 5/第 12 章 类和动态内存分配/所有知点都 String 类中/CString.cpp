#include "CString.h"
#include <cstring>


int CString::amount = 0;

CString::CString(const char *p)
{
	++amount;
    pstr = new char[strlen(p)+1];
	strcpy(pstr, p);

	cout<<"构造(...) 数量: "<< amount <<endl<<endl;
	Init();
}

CString::CString()
{
	++amount;

	pstr = new char[1];
	pstr[0] = '\0';

	cout<<"构造() 数量: "<< amount <<endl<<endl;

	Init();
}

void CString::Init(void)
{
	size = 0;
}

int CString::Size(void)
{
	return strlen(pstr);
}

int CString::GetAmout(void)
{
	return amount;
}

CString & CString::operator=(const CString & str)
{
	if (this == &str)
		return *this;

	delete [] pstr;

	pstr = new char[strlen(str.pstr)+1];
	strcpy(pstr, str.pstr);

	return *this;
}

bool operator==(const CString & str1, const CString & str2)
{
	return (strcmp(str1.pstr, str2.pstr) == 0);
}

bool operator>(const CString & str1, const CString & str2)
{
	return (strcmp(str1.pstr, str2.pstr) > 0);
}

bool operator<(const CString & str1, const CString & str2)
{
	return (strcmp(str1.pstr, str2.pstr) < 0);
}


bool operator==(const char *p, const CString & str2)
{
	return (strcmp(p, str2.pstr) == 0);
}

bool operator>(const char *p, const CString & str2)
{
	return (strcmp(p, str2.pstr) > 0);
}

bool operator<(const char *p, const CString & str2)
{
	return (strcmp(p, str2.pstr) < 0);
}


const char CString::operator[](const int suffix) const
{
	return pstr[suffix];
}

char & CString::operator[](const int suffix)
{
	return pstr[suffix];
}


ostream & operator<<(ostream & os, CString & str)
{
	os<< str.pstr <<endl;
	return os;
}

istream & operator>>(istream & is, CString & str)
{
	char* tp = new char[str.GetSize()+1];
	is.get(tp, str.GetSize()+1);

	if (is)
	{
		delete [] str.pstr;
		str.pstr = tp;
	}

	while(cin || tp[0] != '\0')
		break;

	
	return is;
}

int CString::GetSize(void)
{
	return Size();
}

CString::~CString()
{
	--amount;
	//cout<<"析构："<< pstr <<endl;
	delete [] pstr;
}
