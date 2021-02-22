#include <stdio.h>

int reverse(int x)
{
    if (x == 0)
    {
        return 0;
    }

    int m = 0;
    while (x != 0)
    {
        m = m * 10 + x % 10;
        x = x / 10;
    }
    long int MAX = 2147483647;
    long int MIN = -2147483648;
    /*if (m < 2147483647 && m > -2147483648)
    {
        return m;
    }
    else
    {
        return 0;
    }*/

    return m > MAX || m < MIN ? 0 : m;
}

int main()
{
	int x = 0;
	scanf("%d", &x);
    int m = reverse(x);

    printf("%d", m);
	return 0;
}