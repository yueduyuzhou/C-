#include <stdio.h>

void main ()

{
	int a=1,b=1,c;
	for (c=1;c<=10;c++)
	{
		printf ("%d\n%d\n",a,b);
		a=a+b;
		b=b+a;
	}
	printf ("\n");
}