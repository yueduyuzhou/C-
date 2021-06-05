#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeatedStringMatch(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max = len_b / len_a + 2;
    char* newstr = (char*)calloc((max * len_a + 1), sizeof(char));
    if (newstr == NULL) { return -1; }

    for (int i = 0; i < max; i++)
    {
        //每次循环，追加一个字符串a
        strcat(newstr, a);

        char* tmp = NULL;
        //追加到newstr长度大于等于b的长度时，开始在newstr查找有没有子串b
        if (strlen(newstr) >= strlen(b))
        {
            tmp = strstr(newstr, b);
        }
        //没有继续循环，否则返回i+1
        if (tmp == NULL) { continue; }
        else { return i + 1; }
    }

    free(newstr);
    newstr = NULL;
    return -1;
}


int main()
{



    system("pause");

    exit(0);
}