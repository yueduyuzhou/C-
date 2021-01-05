#include <stdio.h>

int main()
{
	int a,s,d;
	scanf("%d%d",&a,&s);
	if (a==s)
	{
		a=++a;
		s=--s;
	}
	else
	{
		a=a+s;
	}
	printf("%d,%d",a,s);
	return 0;
}