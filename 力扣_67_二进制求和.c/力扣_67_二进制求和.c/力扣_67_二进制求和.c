#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reverse(char* ch)
{
    int left = 0;
    int right = strlen(ch) - 1;

    while (left < right)
    {
        char tmp = ch[left];
        ch[left] = ch[right];
        ch[right] = tmp;
        left++, right--;
    }
}

char* addBinary(char* a, char* b) {
    int len_a = strlen(a), len_b = strlen(b);
    int len = len_a > len_b ? len_a : len_b;
    int i = 0, flag = 0;
    char* res = malloc(sizeof(char) * (len + 2));
    len_a--, len_b--;
    while (len_a >= 0 && len_b >= 0)
    {
        res[i] = a[len_a] + b[len_b] - '0' + flag;
        if (res[i] == '2')
        {
            flag = 1;
            res[i] = '0';
        }
        else if (res[i] == '3')
        {
            flag = 1;
            res[i] = '1';
        }
        else
        {
            flag = 0;
        }
        i++;
        len_a--, len_b--;
    }

    while (len_a >= 0)
    {
        res[i] = a[len_a] + flag;
        if (res[i] == '2')
        {
            flag = 1;
            res[i] = '0';
        }
        else
        {
            flag = 0;
        }
        i++;
        len_a--;
    }
    while (len_b >= 0)
    {
        res[i] = b[len_b] + flag;
        if (res[i] == '2')
        {
            flag = 1;
            res[i] = '0';
        }
        else
        {
            flag = 0;
        }
        i++;
        len_b--;
    }

    if (flag == 1) { res[i++] = '1'; }

    res[i] = '\0';

    Reverse(res);

    return res;
}

int main()
{
    addBinary("1", "111");
	system("pause");
	return 0;
}