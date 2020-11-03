#include "Link.h"

int main(void)
{
	Link * link[4]  = 
	{
	new Link(1),
	new Link(2),
	new Link(3),
	new Link(4)
	};

	ClassLink * pLink = new ClassLink();

	pLink->heact(link);

	pLink->Show();



	ClassLink * ppLink = new ClassLink();

	ppLink->heact(new Link(11));
	ppLink->heact(new Link(11));
	ppLink->heact(new Link(12));
	ppLink->heact(new Link(13));

	ppLink->Show();

	return 0;
}