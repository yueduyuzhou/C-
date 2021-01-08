#include <stdio.h>

int main()
{
    char first_letter_day, second_letter_day;
    printf("输入星期的首字母：");
    scanf_s("%c", &first_letter_day,1);
    char waste = getchar();   //接收上面产生的一个\n

    if (first_letter_day == 'M')     //判断首字母选择打印日期
    {
        printf("星期一\n");
    }
    else if (first_letter_day == 'T')
    {
        printf("请输入星期的第二个字母：");    //由于星期二和星期四首字母相同，根据第二个字母再进行判断
        scanf_s("%c", &second_letter_day,1);
        if (second_letter_day == 'u')
        {
            printf("星期二\n");
        }
        else if (second_letter_day == 'h')
        {
            printf("星期四\n");
        }
    }
    else if (first_letter_day == 'W')
    {
        printf("星期三\n");
    }
    else if (first_letter_day == 'F')
    {
        printf("星期五\n");
    }
    else     
    {
        printf("请输入星期的第二个字母：");    //由于星期六和星期日首字母相同，根据第二个字母再进行判断
        scanf_s("%c", &second_letter_day,1);
        if (second_letter_day == 'a')
        {
            printf("星期六\n");
        }
        else if (second_letter_day == 'u')
        {
            printf("星期日\n");
        }
    }
    //main ();   //重复执行
    return 0;
}