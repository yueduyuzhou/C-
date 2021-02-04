#include <stdio.h>

int NumberDig(int n)
{
	int len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return len;
}

int main()
{
	int num = 10;
	int flag = 0;
	while (num < 100)
	{
		if (NumberDig(809 * num) != 4 || NumberDig(8 * num) != 2 || NumberDig(9 * num) != 3)
			num++;
		else
			flag = 1;
		if (flag == 1)
			break;
	}
	printf("%d\n%d", num, 809 * num);
	return 0;
}