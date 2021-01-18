#include <stdio.h>

int main()
{
	int *num1, *num2, *num3;
	int a = 0, b = 0, c = 0, tmp = 0;

	scanf("%d%d%d", &a, &b, &c);
	num1 = &a;
	num2 = &b;
	num3 = &c;
	printf("%d\t%d\t%d\n", *num1, *num2, *num3);

	if (*num1 > *num2)
	{
		tmp = *num1;
		*num1 = *num2;
		*num2 = tmp;
	}
	if (*num1 > *num3)
	{
		tmp = *num1;
		*num1 = *num3;
		*num3 = tmp;
	}
	if (*num2 > *num3)
	{
		tmp = *num2;
		*num2 = *num3;
		*num3 = tmp;
	}
	printf("%d\t%d\t%d\n", *num1, *num2, *num3);
	return 0;
}