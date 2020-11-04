#include "Link.h"

int main(void)
{
	B * b[4]  = 
	{
		new B(1.1),
		new B(2.2),
		new B(3.3),
		new B(4.4)
	};

	Link<B*> * pLink = new Link<B*>();
	pLink->heact(b);
	pLink->Show();



	Link<A*> * ppLink = new Link<A*>();
	ppLink->heact(new A(11));
	ppLink->heact(new A(11));
	ppLink->heact(new A(12));
	ppLink->heact(new A(13));

	ppLink->Show();

	return 0;
}