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
	printf ("����������������");
	scanf ("%d%d",&a,&b);
	c=max (a,b);
	printf ("�ϴ����Ϊ%d\n",c);
	return 0;
}