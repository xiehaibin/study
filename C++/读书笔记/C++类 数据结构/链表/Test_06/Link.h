#ifndef  List_
#define  List_

#include "A.h"
#include "B.h"

template<class T>
class Link
{
public:
	Link(void);

	T heact(T pa[]);
	T heact(T pa);
	void Show(void);

	T p;
	T r;
};

template<class T>
Link<T>::Link(void)
{
	p = r = NULL;
}

template<class T>
T Link<T>::heact(T pa[])
{
	p = r = pa[0];
	for (int i = 1; i < 4; i++)
	{
		r->next = pa[i];
		pa[i]->prior = r;
		r = pa[i];
	}

	r->next  = p;
	p->prior = r;

	return NULL;
}

template<class T>
T Link<T>::heact(T pa)
{
	if (p == NULL)
	{
		p = pa;
		r = p;
	}
	r->next = pa;
	pa->prior = r;
	r = pa;

	r->next = p;
	p->prior = r;
	
	return NULL;
}

template<class T>
void Link<T>::Show(void)
{
	T r = p;

	while(r->next != p)
	{
		cout<< r->n <<"->";
		r = r->next;
	}
	cout<< r->n <<endl;
}

#endif


