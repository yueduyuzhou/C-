#include <stdio.h>

int main()
{    //待完善
    int arr[13] = { 1,3,7,11,13,17,19,21,25 };
    int num = 0, i = 0, n = 0, m = 9;

    printf("\n插入前数组是:>");
    for (i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);    //输出原数组
    }


    printf("\n输入要插入的数据:>");
    scanf("%d", &num);    //输入要插入的数据


    if (num % 2 == 1)    //判断数据是否符合数组规律
    {
        for (i = 0; i < m; i++)
        {
            if (arr[i] > num)    //判断数据位置
            {
                for (n = m - 1; n >= i; n--)
                {
                    arr[n + 1] = arr[n];
                }
                arr[i] = num;
                break;
            }
            else if (num > arr[m - 1])    //当数据符合规律且大于原数组最大值，直接赋值在最后
            {
                arr[m] = num;    //赋值
            }
        }
    }
    else    //但数据不符合规律时，重新输入
    {
        printf("\n输入的数据不合法，再次输入:>\n");
        main();
    }


    printf("\n插入后的数组是:>");
    for (i = 0; i < m + 1; i++)
    {
        printf("%d ", arr[i]);    //输出插入后数组
    }


    return 0;
}
