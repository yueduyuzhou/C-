#include <stdio.h>

int max (int x,int y)
{
	
	if (x<y)
	{
		int z;
		z=x;
		x=y;
		y=z;
	}
	return x;
}

int main ()

{
	int a,b,c;
	printf ("请输入两个整数：");
	scanf ("%d%d",&a,&b);
	c=max (a,b);
	printf ("较大的数为%d\n",c);
	return 0;
}