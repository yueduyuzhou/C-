#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int i = 0;
    int j = 0;

    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }

    if (s[i] == '\0') { return true; }
    else { return false; }
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int findLUSlength(char** strs, int strsSize) {
    int i = 0;
    int j = 0;
    int max = -1, flag = 0;

    while (i < strsSize)
    {
        j = 0, flag = 0;
        while (j < strsSize)
        {
            if (i != j && strlen(strs[i]) <= strlen(strs[j]))
            {
                //printf ("%d", Max (max, FindLUSTwoStr(strs[i], strs[j])));
                if (isSubsequence(strs[i], strs[j]))
                {
                    flag = 1;
                    break;
                    //return -1;
                }
            }
            j++;
        }
        if (flag == 0)
        {
            int tmp = strlen(strs[i]);
            max = Max(max, tmp);
        }
        i++;
    }

    return max;
}

/****************************************************************************************************************************************/
bool isSubsequence(char* s, char* t) {
    int i = 0;
    int j = 0;

    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }

    if (s[i] == '\0') { return true; }
    else { return false; }
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int findLUSlength(char** strs, int strsSize) {
    int i = 0;
    int max = -1;

    while (i < strsSize)
    {
        int j = 0, flag = 0;
        while (j < strsSize)
        {
            if (i != j && strlen(strs[i]) <= strlen(strs[j]))
            {
                //printf ("%d", Max (max, FindLUSTwoStr(strs[i], strs[j])));
                if (isSubsequence(strs[i], strs[j]))
                {
                    flag = 1;
                    break;
                    //return -1;
                }
            }
            j++;
        }
        if (flag == 0)
        {
            int tmp = strlen(strs[i]);
            max = Max(max, tmp);
        }
        i++;
    }

    return max;
}

int main()
{
    char** a = (char**)malloc(sizeof(char*) * 3);
    a[0] = (char*)malloc(sizeof(char) * 4);
    a[1] = (char*)malloc(sizeof(char) * 4);
    a[2] = (char*)malloc(sizeof(char) * 3);
    a[0] = "aaa";
    a[1] = "aaa";
    a[2] = "aa";


    findLUSlength(a, 3);

	system("pause");

	return 0;
}