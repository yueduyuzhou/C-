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


    /* 1��ȷ��base case */
    int dp[amount + 1];
    dp[0] = 0;
    /* 2������ֵΪ1��ʼ��������dpֵ */
    for (int i = 1; i < amount + 1; i++) {
        /* 2.1��ȷ��״̬����ǰ��ֵ�� dp ֵΪ amount + 1 */
        dp[i] = amount + 1;
        /* 2.2��ȷ��ѡ�񣺼�ΪӲ�ҵ���ֵ
         * ���μ��㵱ǰdpֵ�Ƿ�����ٷ�
         */
        for (int j = 0; j < coinsSize; j++) {
            /* �ж������� i > coins[j](1��2��5) */
            if (i >= coins[j]) {
                /* dp(amount) = min(dp(amount - coins[1��2��5])) + 1 */
                dp[i] = (dp[i - coins[j]] + 1) < dp[i] ? (dp[i - coins[j]] + 1) : dp[i];
            }
        }
    }
    /* 3������ǰӲ�Ҳ��ܱ��ٷ֣��򷵻�-1 */
    return dp[amount] < amount + 1 ? dp[amount] : -1;

}