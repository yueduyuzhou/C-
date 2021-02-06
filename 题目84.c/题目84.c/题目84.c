#include <stdio.h>
#include <stdbool.h>

//判断素数，是返回true，否返回false
bool PrimeJudeg(int n)
{
	int m = 0;
	int flag = 0;
	for (m = 2; m < n / 2; m++)
	{
		if (n % m == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return true;
	else if (flag == 1)
		return false;
}

int main()
{
	int num = 0;
	int tmp = 0;
	int flag = 0;
	printf("输入一个偶数:>");
	scanf("%d", &num);
	for (tmp = 2; tmp < num; tmp++)
	{
		if (PrimeJudeg(tmp) && PrimeJudeg(num - tmp))
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		printf ("\n\n偶数%d能由素数%d和%d相加产生\n", num, tmp, num - tmp);
	else if (flag == 0)
		printf ("\n\n偶数%d无法由两个素数相加产生\n", num);
	return 0;
}