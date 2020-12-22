#include <stdio.h>

int main ()

{
	int i,j;
	for (i=1;i<=10;i++)
	{
		for (j=1;j<=i;j++)
			printf ("%c%c",168,128);
		printf ("\n");
	}
	
	return 0;
}