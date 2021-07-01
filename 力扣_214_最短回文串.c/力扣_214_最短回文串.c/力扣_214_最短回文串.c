#include <stdio.h>
#include <stdlib.h>

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    int fail[len + 1];
    memset(fail, -1, sizeof(fail));

    int i = 1;
    while (i < len)
    {
        int j = fail[i - 1];
        while (j != -1 && s[j + 1] != s[i])
        {
            j = fail[j];
        }
        if (s[j + 1] == s[i])
        {
            fail[i] = j + 1;
        }
        i++;
    }

    int bast = -1;
    i = len - 1;
    while (i >= 0)
    {
        while (bast != -1 && s[bast + 1] != s[i])
        {
            bast = fail[bast];
        }
        if (s[bast + 1] == s[i])
        {
            bast++;
        }
        i--;
    }

    int len_res = len - bast - 1;
    char* res = malloc(sizeof(char) * (len_res + len + 1));
    i = 0;
    while (i < len_res)
    {
        res[i] = s[len - i - 1];
        i++;
    }
    i = 0;
    while (i < len)
    {
        res[i + len_res] = s[i];
        i++;
    }
    res[len_res + len] = '\0';

    return res;
}

int main()
{

	system( "pause" );
	exit(0);
}