#include <stdio.h>

int main ()
{
	int a,s,d,z;
	printf ("����ˮ�ɻ�����");
	for (a = 100;a < 1000;a++)
	{
		s = a/100;		//ȡ����λ
		d = (a/10)%10;  //ȡ��ʮλ
		z = (a%100)%10; //ȡ����λ
		if (a == s*s*s+d*d*d+z*z*z)
		{
			printf (" %d ",a);
		}
	}
	return 0;
}