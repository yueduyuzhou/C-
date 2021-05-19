#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int My_compare(const char** a, const char** b)
{
    if (strlen(*a) > strlen(*b)) { return -1; }
    else if (strlen(*a) < strlen(*b)) { return 1; }

    int i = 0;
    while (a[0][i] != '\0')
    {
        if (a[0][i] < b[0][i]) { return -1; }
        else if (a[0][i] > b[0][i]) { return 1; }
        i++;
    }

    return 1;
}

bool Subseries(char* s, char* di)
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0' && di[j] != '\0')
    {
        if (s[i] == di[j]) { j++; }
        i++;
    }

    if (di[j] == '\0') { return true; }
    else { return false; }
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    int i = 0;
    int flag = 0;
    unsigned int maxlen = 0;
    char* res = NULL;

    //排序char**（从长到短，等长按字典序从小到大排）
    qsort(dictionary, dictionarySize, sizeof(char*), My_compare);

    //简单迭代
    while (i < dictionarySize)
    {
        if (Subseries(s, dictionary[i]))
        {
            if (strlen(dictionary[i]) > maxlen)
            {
                res = dictionary[i];
                maxlen = strlen(dictionary[i]);
            }
            flag = 1;
        }
        i++;
    }

    if (flag == 0) { return ""; }
    return res;
}

int main()
{

    char** c = (char**)malloc(sizeof(char*) * 2);
    //c[0] = (char*)malloc(sizeof(char) * 2);
    //c[1] = (char*)malloc(sizeof(char) * 2);
    //c[2] = (char*)malloc(sizeof(char) * 2);

    //c[0] = "a";
    //c[1] = "b";
    //c[2] = "c";

    c[0] = (char*)malloc(sizeof(char) * 4);
    c[1] = (char*)malloc(sizeof(char) * 4);
    c[0] = "abe";
    c[1] = "abc";
    findLongestWord("abpcplea", c, 3);

    return 0;
}