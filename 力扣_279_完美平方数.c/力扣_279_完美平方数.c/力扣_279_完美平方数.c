#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int numSquares(int n) {
    int sqnum = sqrt(n);
    //printf ("%d", sqnum);

    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    assert(dp);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = n;
        //printf ("%d", dp[i]);
    }

    int* sqarr = (int*)malloc(sizeof(int) * (sqnum + 1));
    assert(sqarr);
    for (int i = 0; i < sqnum + 1; i++)
    {
        sqarr[i] = i * i;
        //printf ("%d", sqarr[i]);
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sqnum + 1; j++)
        {
            if (sqarr[j] > i) { break; }
            dp[i] = Min(dp[i], dp[i - sqarr[j]] + 1);
        }
    }

    return dp[n];
    //return 3;
}

int main()
{
    int a = numSquares(10000);
    printf("%d", a);
	return 0;
}