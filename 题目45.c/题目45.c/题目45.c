#include <stdio.h>

int main()
{
	register int a = 0;    //直接将变量a定义在寄存器
	//int a = 0;
	long long int sum = 0;

	for (a = 0; a < 100000; a++)
	{
		sum += a;
		printf("%lld\t", sum);
	}

	return 0;
}