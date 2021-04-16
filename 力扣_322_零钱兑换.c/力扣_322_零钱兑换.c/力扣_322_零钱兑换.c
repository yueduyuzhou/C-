/*void swap (int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort (int* arr, int Size)
{
    int i, j;
    for (i = 0; i < Size - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < Size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) {swap(arr + j, arr + j + 1); flag = 1;}
        }
        if (flag == 0) {break;}
    }
}

int Min (int a, int b)
{
    return a < b ? a : b;
}*/

int coinChange(int* coins, int coinsSize, int amount) {
    /*if (amount == 0) {return 0;}

    bubbleSort(coins, coinsSize);

    //for (int i = 0; i < coinsSize; i++)
    //    printf("%d ",coins[0]);
    //    printf("%d ",coins[1]);
    //    printf("%d ",coins[2]);
    //    printf("%d ",coins[3]);

    unsigned int res = 2147483648;
    int restmp = 0;
    //int amtmp = amount;
    int tmp1 = 0;
    int flag = 0;

    for (tmp1 = coinsSize - 1; tmp1 >= 0; tmp1--)
    {
        int amtmp = amount;
        int tmp = tmp1;
        //printf("%d ", amtmp);
        //printf ("%d ", tmp);
        while (amtmp > 0 && tmp >= 0)
        {
            if (coins[tmp] <= amtmp)
            {
                restmp += amtmp / coins[tmp];
                amtmp %= coins[tmp];
                //printf ("%d ", amtmp);
            }
            tmp--;
        }
        if (amtmp == 0) {res = Min (res, restmp); flag = 1;}
    }

    if (flag == 0) {return -1;}
    else {return res;}*/


    /* 1、确定base case */
    int dp[amount + 1];
    dp[0] = 0;
    /* 2、从面值为1开始，计算其dp值 */
    for (int i = 1; i < amount + 1; i++) {
        /* 2.1、确定状态：当前面值的 dp 值为 amount + 1 */
        dp[i] = amount + 1;
        /* 2.2、确定选择：即为硬币的面值
         * 依次计算当前dp值是否可以再分
         */
        for (int j = 0; j < coinsSize; j++) {
            /* 判断条件是 i > coins[j](1、2、5) */
            if (i >= coins[j]) {
                /* dp(amount) = min(dp(amount - coins[1、2、5])) + 1 */
                dp[i] = (dp[i - coins[j]] + 1) < dp[i] ? (dp[i - coins[j]] + 1) : dp[i];
            }
        }
    }
    /* 3、若当前硬币不能被再分，则返回-1 */
    return dp[amount] < amount + 1 ? dp[amount] : -1;

}