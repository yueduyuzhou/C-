#include <stdio.h>

int isprime(int n)
{
	int i,flag=1;
	for (i=2;i<n;i++)
		if (n%i==0)
		{
			flag=0;
			i=n;
		}
		return flag;
}

int main()

{
	int m;
	for (m=2;m<300;m++)
		if (isprime(m)==1)
			printf ("%d\t",m);
		return 0;
}	