#include <iostream>
using namespace std;

class Queue
{
public :
	struct link
	{
		int data;
		link* next;
	}; // 在类中声明的结构 类 枚举称为被嵌套在类中，这种声明不会创建数据对象 而只是指于可以在类中
	   // 使用类型  如果在私有部只能被这个类使用 如果是在公有部分进行的 可以使用作用域解析操作来使
	   // 被声明的类型 

	const int MAX;
	int & length;

public :
	Queue(int a, int & b) : MAX(a), length(b)
	{
	   // 非静态consr类成员 引用类成员 const类成员 都必使用参数列表进行初始化
	   // 数据被初化的xuen序与它们出现在类声明中的xuen序相同 与参数列表无关
	}
private : // 将此几种方法放在私有部分的好处
	Queue(const Queue & q);
	Queue operator=(const Queue & Q);
	// 1.避免生成默认的方法定义 2. 因为方法是私有的 因此方不能被广反使用  n v 是Queue的对象
	// Queue q(v) v = n 编绎器将允许这样做

	void Get(void) const
	{
		cout<< MAX <<endl;
		cout<< length <<endl;
	}
};

int main(void)
{
	int a = 100;
	int b = 200;

	Queue queue(a, b);
	queue.Get();

	//cout<< sizeof(queue) <<endl;

	Queue::link lk;
	return 0;
}