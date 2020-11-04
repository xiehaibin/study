#include <cstring>
#include <iostream>
using namespace std;

class A
{
private :
	char *pstr;
	int a;

public :
	A(char *p = "xie")
	{
		pstr = new char[strlen(p)+1];
		strcpy(pstr, p);
		pstr[strlen(p)] = '\0';

		cout<<"构造：：：：: "<<strlen(p)<<endl;
	}

	/*A(const A &t)
	{
		pstr = new char[strlen(t.pstr)+1];
		strcpy(pstr, t.pstr);
		pstr[strlen(t.pstr)] = '\0';

		cout<<"构造.................."<<endl;
	}*/

	void get(A a) const
	{
		cout<< a.pstr <<endl;
	}

	~A(void)
	{
		cout<<"%%%%%%%%%"<<endl;
		delete [] pstr;
	}
};

int main(void)
{
	A a("xie hai bing");
	A b;
	b.get(a);   // 编绎器  编绎 和 连接 都没有错 但运行时出错 打开上面的的代码将能安全的运行
	            // 因为传给函数是安值传递的 将产生复本（此时复本和原对象都指上同一个动态分配的成员pstr） 
	            // 函数结束时将调用 对象复本的析构 从而将动态
	            // 分配的动员4放掉   同对象指向的动态动员将不在存在

	// !!！如果动态为本地C++类的成员分配空间 则必须实现复缺构造函数

	return 0;
}