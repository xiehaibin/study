#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

string & ToLower(string & str); 
char toLower(char ch)
{
	return tolower(ch); // ��һ���ַ���д תСд�ķ���
}

int main(void)
{
	vector<string>vstring;

	cout<<"�������ַ����� ��noΪ�������룺";
	string str;
	while(cin>>str && str != "no" && str != "NO")
		vstring.push_back(str);
	copy(vstring.begin(), vstring.end(), ostream_iterator<string>(cout, " "));
	cout<<endl;

	set<string>setString;
	
	transform(vstring.begin(), vstring.end(), insert_iterator<set<string>>(setString, setString.begin()), 
		      ToLower);  // ��ת���õ� �浽 ����Ϊset<string> ��������
	cout<<endl;

	map<string, int>mapString;
	set<string>::iterator is;

	for (is = setString.begin(); is != setString.end(); is++)
		mapString[*is] = count(vstring.begin(), vstring.end(), *is);

	map<string, int>::iterator si;
   for (si = mapString.begin(); si != mapString.end(); si++)
	   cout<< *is <<" : "<< mapString[*is] <<endl; 

	return 0;
}

string & ToLower(string & str)
{
	transform(str.begin(), str.end(), str.begin(), toLower);
	return str;
}