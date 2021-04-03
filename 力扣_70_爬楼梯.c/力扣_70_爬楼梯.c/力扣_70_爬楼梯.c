#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) { return 1; }

    int prev = 1;
    int cur = 1;
    int tmp = 0;

    for (int i = 2; i <= n; i++)
    {
        tmp = prev + cur;
        prev = cur;
        cur = tmp;
    }

    return cur;
}

int main()
{

	return 0;
}