#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0, n = 0, sum = 0;
	printf("100以内的素数有：");
	for (i = 2; i <= 100; i++)    //在1到100中寻找
	{ 
		int flag = 0;    //立标记，重置标记
		for (n = 2; n <= sqrt(i); n++)
		{
			if (i % n == 0)    //判断
			{
				flag = 1;
				break;    //跳出
			}
		}
		if (flag == 0)
		{
			printf("%d ", i);
			sum += i;    //算和
		}
	}
	printf("\n和为：");
	printf("%d\n", sum);
	return 0;
}