#include <stdio.h>

int main()
{
	register int a = 0;    //ֱ�ӽ�����a�����ڼĴ���
	//int a = 0;
	long long int sum = 0;

	for (a = 0; a < 100000; a++)
	{
		sum += a;
		printf("%lld\t", sum);
	}

	return 0;
}