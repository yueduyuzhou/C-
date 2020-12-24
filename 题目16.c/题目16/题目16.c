#include <stdio.h>

int main()
{
	int n, m, i, b, s;
	int a = 0, c = 0;
	int arr[20] = { 0 };
	scanf_s("%d", &n);
	scanf_s("%d", &m);

	if (m > n)
	{
		s = m;
		m = n;
		n = s;
	}
	for (i = m; i != 1; i--)
	{
		if (m % i == 0)
		{
			if (n % i == 0)
			{
				printf("n和m的最大公约数为%d。\n", i);
				break;
			}
		}
	}
	if (i == 1)
	{
		printf("n和m没有最大公约数\n");
	}
	//求最小公倍数（下面有bug）
	for (i = 2; i <= m; i++)
	{
		if (n % i == 0) //判断是否能被n整除
		{
			if (m % i == 0)  //判断是否能被m整除
			{
				a = 0;
				arr[a] = i; //保存公约数
				a++;
				m = m / i;
				i = 2;
			}
		}
	}
	for (b = 0; b <= a; b++)
	{
		c = 1;
		c = c * arr[b]; //所有公约数的积
	}
	printf("n和m的最小公倍数为%d。\n", c);

	return 0;
}