#pragma once
#include "Text.h"
#include <stdio.h>

class ClassLink
{
public:
	ClassLink(void);

	Link* heact(Link* link[4]);
	Link* heact(Link* link);
	void Show(void);

	Link* p;
	Link* r;
};

