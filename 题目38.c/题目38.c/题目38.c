#include <stdio.h>

int main()
{
    int sum = 0;
    //int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};    //试验数据
    int arr[3][3] = { 0 };    
    int i = 0, j = 0;
    for (i = 0; i < 3; i++)        //第i行
    {                              //遍历数
        for (j = 0; j < 3; j++)    //第j列
        {
            printf("输入第%d行第%d列数据:>", i, j);
            scanf("%d", &arr[i][j]);    //赋值
        }
    }
    printf("\n矩阵如下:>\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", arr[i][j]);    //将数据按矩阵格式输出
        }
        printf("\n");
    }
    sum = arr[0][0] + arr[0][2] + arr[2][0] + arr[2][2];    //算对角和值
    printf("\n对角线值相加位为:>%d\n", sum);

    return 0;
}