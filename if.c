#include <stdio.h>

int main()

{
	int a,s,d;
	printf("������������");
	scanf("%d%d",&a,&s);
	if(a>s)
	{
	d=a;a=s;s=d;
	}
	printf("%d\t%d",a,s);
	return 0;
}
