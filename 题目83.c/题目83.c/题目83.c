#include <stdio.h>

//该题目没有说明具体位数和数字不能重复出现
int main()
{
	unsigned int n = 0;
	unsigned int m = 0;
	unsigned int sum = 0;
	for (n = 1; n < 9; n++)
	{
		if (n == 1)
			m = 4;
		else if (n == 2)
			m = 4 * 7;
		else
			m *= 8;
		printf("%d位数有%d种奇数组合;\n\n", n, m);
		sum += m;
	}
	printf("1至8位共有%d种奇数组合\n", sum);
	return 0;
}