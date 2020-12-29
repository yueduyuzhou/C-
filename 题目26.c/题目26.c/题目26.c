#include <stdio.h>

void Factorial(int i,long long fact)
{
	fact *= i;
	i--;
	if (i != 1)
	{
		Factorial(i, fact);
	}
	if (i == 1)
	{
		printf("%lld\n", fact);
	}
}

void main()
{
	int i = 0;
	long  long fact = 1;
	scanf_s("%d", &i);
	Factorial(i, fact);
	main();
}