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

char* addStrings(char* num1, char* num2) {
    int len_1 = strlen(num1);
    int len_2 = strlen(num2);
    int len = len_1 > len_2 ? len_1 : len_2;
    int flag = 0;
    int i = 0;
    char* res = malloc(sizeof(char) * (len + 2));

    len_1--, len_2--;
    while (len_1 >= 0 && len_2 >= 0)
    {
        res[i] = num1[len_1] + num2[len_2] - '0' + flag;
        if (res[i] >= ':')
        {
            flag = 1;
            res[i] = res[i] - 10;
        }
        else
        {
            flag = 0;
        }
        i++;
        len_1--, len_2--;
    }

    while (len_1 >= 0)
    {
        res[i] = num1[len_1] + flag;
        if (res[i] == ':')
        {
            flag = 1;
            res[i] = res[i] - 10;
        }
        else
        {
            flag = 0;
        }
        i++;
        len_1--;
    }
    while (len_2 >= 0)
    {
        res[i] = num2[len_2] + flag;
        if (res[i] == ':')
        {
            flag = 1;
            res[i] = res[i] - 10;
        }
        else
        {
            flag = 0;
        }
        i++;
        len_2--;
    }

    if (flag == 1) { res[i++] = '1'; }
    res[i] = '\0';

    Reverse(res);

    return res;
}

int main ()
{
	
    addStrings("1", "9");

	system("pause");
	return 0;
}