#include <stdio.h>
#include <math.h>

int main()
{
	int a,d = 1,s,z = 0;
	for (a = 101;a >= 101 && a <= 200;a+=2)
	{
		for (s = 2;s <= sqrt(a);s++)
		{
			if(a%s == 0)
			{
				d = 0;
			}
		}
		if (d != 0)
		{
			printf ("%d   ",a);
            z++;     
		}
		d = 1;
	}
	printf ("\n");
	printf ("101��200�ڹ���%d��������\n",z);
	return 0;
}