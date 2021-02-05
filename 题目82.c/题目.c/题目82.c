#include <stdio.h>

int main()
{
	int a = 1;
	int n = 0;
	int num = 0;
	printf("输入一个八进制数:>");
	scanf("%d", &num);
	//八进制转十进制：将八进制数按权展开(十六进制，二进制相同)
	//八进制数226 == 十进制数2 * 8的二次方 + 2 * 8的一次方 + 6 * 8的零次方
	while (num != 0)
	{
		n += num % 10 * a;
		a *= 8, num /= 10;
	}
	printf("%d", n);

	return 0;
}