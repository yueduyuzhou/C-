#include <stdio.h>

int main()
{
    int num = 0, arr[5], i = 0, a = 0;
    printf("输入一个五位数:");
    scanf_s("%d。", &num);
    if (num > 9999 && num < 100000)
    {
        a = num;   //保存数值

        for (i = 0; i < 5; i++)
        {
            arr[i] = num % 10;   //分别获取个，十，百，千，万位并存入数组
            num = num / 10;   //删除末位
        }
        if (arr[0] == arr[4] && arr[1] == arr[3])   //判断个位与万位，十位与千位是否都相同
        {
            printf("%d是回文数。\n", a);
        }
        else
        {
            printf("%d不是回文数。\n", a);
        }
    }
    else
    {
        printf ("你输入的数值不符合要求\n");
        printf("请重新");
    }
    //main();   //重复执行
    return 0;
}