#include "stdafx.h"
#include <iostream>
using namespace std;

template<int ObjectSize, int NumofObjects = 20>
class MemPool
{
private:
	//���нڵ�ṹ��
	struct FreeNode
	{
		FreeNode* pNext;
		char data[ObjectSize];
	};

	//�ڴ��ṹ��
	struct MemBlock
	{
		MemBlock* pNext;
		FreeNode data[NumofObjects];
	};

	FreeNode* freeNodeHeader;
	MemBlock* memBlockHeader;

public:
	MemPool()
	{
		freeNodeHeader = NULL;
		memBlockHeader = NULL;
	}

	~MemPool()
	{
		MemBlock* ptr;
		while (memBlockHeader)
		{
			ptr = memBlockHeader->pNext;
			delete memBlockHeader;
			memBlockHeader = ptr;
		}
	}
	void* malloc();
	void free(void*);
};

//������еĽڵ�
template<int ObjectSize, int NumofObjects>
void* MemPool<ObjectSize, NumofObjects>::malloc()
{
	//�޿��нڵ㣬�������ڴ��
	if (freeNodeHeader == NULL)
	{
		MemBlock* newBlock = new MemBlock();
		newBlock->pNext = NULL;

		//�����ڴ��ĵ�һ���ڵ�Ϊ���нڵ�������׽ڵ�
		freeNodeHeader = &newBlock->data[0];

		//���ڴ��������ڵ㴮����
		for (int i = 1; i < NumofObjects; ++i)
		{
			newBlock->data[i - 1].pNext = &newBlock->data[i];
		}
		newBlock->data[NumofObjects - 1].pNext = NULL;

		//�״������ڴ��
		if (memBlockHeader == NULL)
		{
			memBlockHeader = newBlock;
		}
		else
		{
			//�����ڴ����뵽�ڴ������
			newBlock->pNext = memBlockHeader;
			memBlockHeader = newBlock;
		}
	}

	//���ؿսڵ�������ĵ�һ���ڵ�
	void* freeNode = freeNodeHeader;
	freeNodeHeader = freeNodeHeader->pNext;
	return freeNode;
}

//�ͷ��Ѿ�����Ľڵ�
template<int ObjectSize, int NumofObjects>
void MemPool<ObjectSize, NumofObjects>::free(void* p)
{
	FreeNode* pNode = (FreeNode*)p;
	pNode->pNext = freeNodeHeader;	//���ͷŵĽڵ������нڵ�ͷ��
	freeNodeHeader = pNode;
}



class ActualClass
{
	static int count;
	int No;
	int a;
	float b;
	double c;

public:
	ActualClass()
	{
		No = count;
		count++;
	}

	void print()
	{
		//cout << this << ": ";
		//cout << "the " << No << "th object" << endl;
	}

	void* operator new(size_t size);
	void operator delete(void* p);
};

//�����ڴ�ض���
MemPool<sizeof(ActualClass), 2> mp;
void* ActualClass::operator new(size_t size)
{
	return mp.malloc();
}
void ActualClass::operator delete(void* p)
{
	mp.free(p);
}

int ActualClass::count = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 0; i < 100; i++)
	{
		ActualClass* p1 = new ActualClass;
		delete p1;
	}

	//p1 = new ActualClass;
	//p1->print();

	//ActualClass* p3 = new ActualClass;
	//p3->print();

	//_sleep(10000);
}

