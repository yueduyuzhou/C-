#include <stdio.h>


/***********************************************************************************************************/
//1.这种算法实际复杂度太高

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
/***********************************************************************************************************/
//2.动态规划

int maxProfit(int* prices, int pricesSize) {
    int maxprofits = 0;
    int minprices = 10000;

    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < minprices) { minprices = prices[i]; }
        else if (prices[i] - minprices > maxprofits) { maxprofits = prices[i] - minprices; }
    }

    return maxprofits;
}