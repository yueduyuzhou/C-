#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int maxprofits = 0;

    for (int i = 0; i < pricesSize - 1; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            if (prices[j] - prices[i] > 0)
            {
                maxprofits = Max(maxprofits, prices[j] - prices[i]);
            }
        }
    }

    return maxprofits;
}

int main()
{
    int p[] = { 7,1,5,3,6,4 };
    maxProfit(p, 6);
	return 0;
}