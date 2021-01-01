#include <stdio.h>

int main()

{
	int a=5,b=6,c=7,d=8;
	int m=2,n=2;
	(m=a>b)&&(n=c>d);
	printf("m=%d\tn=%d",m,n);

	return 0;
}