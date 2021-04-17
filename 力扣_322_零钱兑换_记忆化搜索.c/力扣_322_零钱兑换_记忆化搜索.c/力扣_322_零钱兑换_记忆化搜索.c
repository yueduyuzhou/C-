#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

//int arr[10001] = { 0 }; 

//看不太懂

int memoSearch(int* coins, int coinsSize, int amount, int* arr)
{
    //返回条件
    if (amount < 0) { return -1; }

    if (arr[amount] != 0 || amount == 0) { return arr[amount]; }

    int ans = amount + 1;

    for (int i = 0; i < coinsSize; i++)
    {
        if (amount >= coins[i])
        {
            arr[amount - coins[i]] = memoSearch(coins, coinsSize, amount - coins[i], arr);

            if (arr[amount - coins[i]] >= 0)
            {
                ans = Min(ans, arr[amount - coins[i]] + 1);
            }
        }
    }

    return ans > amount ? -1 : ans;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int* memo = (int*)calloc(10001, sizeof(int));
    assert(memo);
    return memoSearch(coins, coinsSize, amount, memo);
}

int main ()
{
    int coins[3] = { 1,2,5 };
    int a = coinChange(coins, 3, 100);

	return 0;
}