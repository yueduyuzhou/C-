#include <stdio.h>

int main()
{
	int i = 0, n = 0, m = 0, x = 0,y = 0;
	double sum = 2/1,a = 0;
	x = n = 2;
	m = 3;
	for (i = 0; i < 19; i++)
	{
		a = (double)m / n;
		n = m;
		m += x;
		sum += a;
		x = n;
		if (i == 18)
		{
			printf("%lf\t\n", sum);
		}
	}
	return 0;
}