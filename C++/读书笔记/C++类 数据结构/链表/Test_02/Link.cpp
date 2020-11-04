#include "Link.h"

ClassLink::ClassLink(void)
{
	p = r = NULL;
}


Link* ClassLink::heact(Link* link[4])
{
	p = r = link[0];

	for (int i = 1; i < 4; i++)
	{
		r->next = link[i];
		link[i]->prior = r;
		r = link[i];
	}

	r->next = p;
	p->prior = r;

	return p;
}

Link* ClassLink::heact(Link* link)
{
	if (p == NULL)
	{
		p = link;
		r = p;
	}
	r->next = link;
	link->prior = r;
	r = link;

	r->next = p;
	p->prior = r;
	
	return NULL;
}

void ClassLink::Show(void)
{
	Link* r = p;

	while(r->next != p)
	{
		cout<< r->n <<"->";
		r = r->next;
	}
	cout<< r->n <<endl;
}


