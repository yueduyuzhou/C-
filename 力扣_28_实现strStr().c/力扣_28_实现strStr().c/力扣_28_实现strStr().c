#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int index_h = 0;
    //int index_n = 0;
    int len_h = strlen(haystack);
    int len_n = strlen(needle);

    while (haystack[index_h] != '\0' && len_h - index_h >= len_n)
    {
        int index_n = 0;
        int index_h_i = index_h;
        while (needle[index_n] != '\0' && haystack[index_h_i] == needle[index_n])
        {
            index_n++;
            index_h_i++;
        }

        if (needle[index_n] == '\0') { break; }

        index_h++;
    }

    if (len_h - index_h < len_n) { return -1; }
    return index_h;
}

int main()
{
    strStr("aaaaa", "bba");

    system("pause");

    exit(0);
}