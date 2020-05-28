#include <iostream>
#include "random.h"

int main()
{
	Random r;
	for (int i = 0; i < 10; ++i)
	{
		r();
	}
	return 0;
}