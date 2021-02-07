#include <stdio.h>

int main()
{
	int num = 0;
	int size = 0;

	printf("输入一个素数:>");
	scanf("%d", &num);

	int n = num;
	int flag = 0;
	while (flag == 0)
	{
		if (n % 9 == 0)
		{
			size++;
			n /= 9;
		}
		else
		{
			flag = 1;
		}
	}

	printf("%d可以被%d个9整除", num, size);
	return 0;
}