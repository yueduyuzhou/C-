#include <stdio.h>

int main()

{
	int x,y,z;
	for (x=1;x<=20;x++)
		for (y=1;y<=33;y++)
		{
			z=100-x-y;
			if (15*x+9*y+z==300)
				printf ("x=%d,y=%d,z=%d\n",x,y,z);
		}
}