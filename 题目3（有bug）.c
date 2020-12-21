#include <stdio.h>

int main ()

{
	int n,i,p;
	for (i=0;i<=10;i++)
	{
		for (p=0;p<=1000;p++)
		{
		
				for (n=0;n<=1000;n++)
					if (i+268==n*n&&i+100==p*p)
						break;
		}
		printf ("这个数是%d。\t",i);
	}		
	return 0;
}