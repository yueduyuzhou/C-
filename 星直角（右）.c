#include <stdio.h>

int main()

{
	int i,j;
	for (i=1;i<=8;i++)
	{
		for (j=1;j<=8-i;j++)
			putchar(' ');
		for (j=1;j<=i;j++)
			putchar('*');
		putchar('\n');
	}
	
	return 0;
}