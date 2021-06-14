#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expandaroundCenter(char* s, int left, int right)
{
    int len_s = strlen(s);
    while (left >= 0 && right < len_s)
    {
        if (s[left] == s[right])
        {
            left--;
            right++;
        }
        else {
            break;
        }
    }

    //跳出 while 时恰好s[left] ！= s[right]
    //回文串长度时 j - i + 1 - 2;
    return right - left - 1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

char* longestPalindrome(char* s) {
    int len_s = strlen(s);
    if (len_s < 2) { return s; }

    int maxlen = 1;
    int begin = 0;

    int i = 0;
    while (i < len_s - 1)
    {
        int len_odd = expandaroundCenter(s, i, i);
        int len_even = expandaroundCenter(s, i, i + 1);

        int cur_maxlen = max(len_odd, len_even);
        if (cur_maxlen > maxlen)
        {
            maxlen = cur_maxlen;
            begin = i - (maxlen - 1) / 2;
        }
        i++;
    }

    printf("%d %d", maxlen, begin);
    i = 0;
    char* res = (char*)malloc(sizeof(char) * (maxlen + 1));
    while (i < maxlen)
    {
        res[i] = s[begin + i];
        i++;
    }
    res[i] = '\0';

    return res;
}

int main ()
{


    system("pause");

    return 0;
}