#include <stdio.h>
#include <stdbool.h>

//�ж��������Ƿ���true���񷵻�false
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
	printf("����һ��ż��:>");
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
		printf ("\n\nż��%d��������%d��%d��Ӳ���\n", num, tmp, num - tmp);
	else if (flag == 0)
		printf ("\n\nż��%d�޷�������������Ӳ���\n", num);
	return 0;
}