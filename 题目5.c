#include <stdio.h>

int main()
{
	int x,y,z,n;
	printf ("����������������\n");
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

	printf ("��������ֵ��С����Ϊ��%d<%d<%d\n",z,y,x);
	return 0;			
}