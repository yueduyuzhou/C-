#include <stdio.h>

int InsertNum(char* s, int a, int to)
{
    int count = 0;
    //��¼��ͬ��ĸ��
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

    //�����ַ���
    for (tmp = 0; tmp < charsSize; tmp++)
    {
        if (chars[tmp] == chars[ch])
        {
            a++;
        }
        else
        {
            //�������֣������´β����λ��
            restmp += InsertNum(chars, a, restmp);
            ch = tmp;
            //��ͬ��ĸ����������Ϊ1
            a = 1;

            //������ĸ
            chars[restmp++] = chars[tmp];
            //printf ("%d ", restmp);
        }
    }
    //��Ŀ�ö��ַ������ȴ���1�ǣ���ѭ�������һ����ĸ���������
    //�������һ����ĸ��
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