#include <stdio.h>

void main()
{
	int i = 0, n = 0, star = 0;
	
	for (n = 1; n <= 7; n++)   //控制行数
	{
		for (i = abs(n - 4); i >= 1; i--)   //每行空格数=行数-4的绝对值
		{
			printf(" ");
		}
		for (star = 1; star <= 7 - 2 * abs(n - 4); star++)   //每行*数=7-2*空格数
		{
			printf("%c", '*');
		}
		printf("\n");   //换行
	}
}