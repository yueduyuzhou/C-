#include <stdio.h>

int prime (int n,int a)
{
	int s=1;
	for (a=2;a<=n-1;a++)
		if (n%a!=0)
			continue;
		else
		{
			s=0;
			break;
		}
	return s;
}

int main ()
{
	int i;
	for (i=100;i<=200;i++)
	{
		if (prime(i)==1)
			printf ("%d",i);
	}
	return 0;
}