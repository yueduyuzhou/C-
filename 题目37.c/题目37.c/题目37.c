#include <stdio.h>

int main()
{   //可完善 
    //int arr[10] = {1,3,5,7,9,2,4,6,8,0};    //初始化试验

    int arr[10] = { 0 };
    int n = 0;
    for (n = 0; n < 10; n++)    //依次输入十个数
    {
        printf("你还没输入到十个数，请继续:>");
        scanf("%d", &arr[n]);
    }

    int i = 0, j = 0;
    for (i = 0; i < 9; i++)    //选择法排序
    {
        for (j = i + 1; j < 10; j++)    //比较
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    int m = 0;
    printf("排列后:>");
    for (m = 0; m < 10; m++)    //依次输出十个数
    {
        printf("%d ", arr[m]);
    }

    return 0;
}