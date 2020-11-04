#pragma once

#ifndef CString_H__
#define CString_H__

#include <iostream>
using namespace std;

class CString
{
private :
	static int amount;
	char* pstr;
	int   size;

public :
	CString(const char* p); // explicit
	CString();
	void Init(void);
	int  Size(void);
	static int GetAmout(void);
    
    CString& operator=(const CString& str);

	friend bool operator==(const CString & str1, const CString & str2);
	friend bool operator>(const CString & str1,  const CString & str2);
	friend bool operator<(const CString & str1,  const CString & str2);

	friend bool operator==(const char *p, const CString & str2);
	friend bool operator>(const char *p,  const CString & str2);
	friend bool operator<(const char *p,  const CString & str2);

	char & operator[](const int suffix);
	const char operator[](const int suffix) const;

	friend ostream & operator<<(ostream & os, CString & str);
	friend istream & operator>>(istream & is, CString & str);
  
	int  GetSize(void);
	~CString(void);
};

#endif 