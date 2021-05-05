#include <stdio.h>

int InsertNum(char* s, int a, int to)
{
    int count = 0;
    //记录相同字母数
    int tutor = a;

    if (a > 999 && tutor > 1)
    {
        int tmp = a % 10;
        a /= 10;
        s[to + 3] = tmp + '0';
        count++;
    }

    if (a > 99 && tutor > 1)
    {
        int tmp = a % 10;
        a /= 10;
        s[to + 2] = tmp + '0';
        count++;
    }

    if (a > 9 && tutor > 1)
    {
        int tmp = a % 10;
        a /= 10;
        s[to + 1] = tmp + '0';
        count++;
    }

    if (a != 0 && tutor > 1)
    {
        int tmp = a % 10;
        a /= 10;
        s[to + 0] = tmp + '0';
        count++;
    }

    //printf ("%d ", count);
    return count;
}

int compress(char* chars, int charsSize) {
    int ch = 0;
    int tmp = 0;
    int a = 0;
    int restmp = 1;

    //遍历字符串
    for (tmp = 0; tmp < charsSize; tmp++)
    {
        if (chars[tmp] == chars[ch])
        {
            a++;
        }
        else
        {
            //插入数字，更新下次插入的位置
            restmp += InsertNum(chars, a, restmp);
            ch = tmp;
            //相同字母计数器设置为1
            a = 1;

            //插入字母
            chars[restmp++] = chars[tmp];
            //printf ("%d ", restmp);
        }
    }
    //题目得定字符串长度大于1是，在循环内最后一个字母数不会插入
    //插入最后一个字母数
    if (charsSize > 1)
    {
        restmp += InsertNum(chars, a, restmp);
    }

    //printf ("%d ", restmp);
    return restmp;
}

int main()
{

    return 0;
}