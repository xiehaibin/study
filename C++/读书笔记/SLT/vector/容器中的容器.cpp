#include <iostream>
#include <vector>
using namespace std;

class A
{
public :
	int aa;
	A(int a) : aa(a) {}
};


int main(void)
{
	vector<A*>list;  // 可以定义成数组
	typedef vector<A*>::iterator iter1;
	
	list.push_back( new A(10) );
	list.push_back( new A(11) );
	list.push_back( new A(12) );
	list.push_back( new A(13) );

	cout<< list.size() <<endl;
	cout<< list.front() <<endl;
	cout<< list[0]->aa <<endl;
// ==========================================

	vector<A*>list2;
	typedef vector<A*>::iterator iter2;
	
	list2.push_back( new A(100) );
	list2.push_back( new A(110) );
	list2.push_back( new A(120) );
	list2.push_back( new A(130) );
	list2.push_back( new A(140) );
	list2.push_back( new A(150) );

	cout<<"===================================="<<endl;
// ===========================================

	vector<vector<A*>>m_List;

	typedef vector<vector<A*>>::iterator iter;

	m_List.push_back(list);
	m_List.push_back(list2);

	cout<< m_List.size() <<endl;



	cout<<"v[0][0] : "<< m_List[0][0]->aa <<endl;
	cout<<"v[0][0] : "<< m_List[1][1]->aa <<endl;

	cout<<"m_List[0] =  : "<< m_List[0].size() <<endl;
	cout<<"m_List[1] =  : "<< m_List[1].size() <<endl;

	cout<<"m_List[0][0] =  : "<< m_List[0][0]->aa <<endl;




	// 编历容器里的容器成员方法
	for (iter first = m_List.begin(); first != m_List.end(); first++ )
	{
		for (iter1 first2 = first->begin(); first2 != first->end(); first2++)
		{
			cout<< (*first2)->aa<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}