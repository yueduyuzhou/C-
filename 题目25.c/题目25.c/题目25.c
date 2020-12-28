#include <stdio.h>

void main()
{
	int n = 0, m = 0;
	long long int sum = 1, factorial = 0;
	for (n = 2; n <= 20; n++)
	{
		for (m = 1; m <= n; m++)
		{
			if (m == 1)
			{
				factorial = 1;
			}
			factorial *= m;
			if (m == n)
			{
				sum += factorial;
			}
		}
	}
	printf("%lld", sum);
}
