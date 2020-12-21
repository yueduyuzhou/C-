#include <stdio.h>

int main()
{
	int x,y,z,n;
	printf ("请输入三个整数：\n");
	scanf ("%d%d%d",&x,&y,&z);
	for(;x<y;)
	{
		n=x;
		x=y;
		y=n;
	}
		for(;x<z;)
		{
			n=x;
			x=z;
			z=n;
		}
			for(;y<z;)
			{
				n=y;
				y=z;
				z=n;
			}

	printf ("这三个数值从小到大为：%d<%d<%d\n",z,y,x);
	return 0;			
}