#include <stdio.h>

int main()
{
	int c, i;
	long long int s = 0, a = 0, n = 0;
	scanf_s("%lld", &a);
	n = a;
	for (c = 1; c < n; c++)
	{
		a = n + a * 10;   //算出a的最大值
		s = a;
	}
	
	for (i = 0; i < a; i++)
	{
		a = a / 10;
		s = s + a;
	}
	printf("%lld", s);
	return 0;
}