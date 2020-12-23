#include <stdio.h>

int main ()
{
	int a,s,d,z;
	printf ("所有水仙花数：");
	for (a = 100;a < 1000;a++)
	{
		s = a/100;		//取出百位
		d = (a/10)%10;  //取出十位
		z = (a%100)%10; //取出个位
		if (a == s*s*s+d*d*d+z*z*z)
		{
			printf (" %d ",a);
		}
	}
	return 0;
}