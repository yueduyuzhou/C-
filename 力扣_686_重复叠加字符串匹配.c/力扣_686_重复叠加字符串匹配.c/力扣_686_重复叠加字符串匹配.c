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
        //ÿ��ѭ����׷��һ���ַ���a
        strcat(newstr, a);

        char* tmp = NULL;
        //׷�ӵ�newstr���ȴ��ڵ���b�ĳ���ʱ����ʼ��newstr������û���Ӵ�b
        if (strlen(newstr) >= strlen(b))
        {
            tmp = strstr(newstr, b);
        }
        //û�м���ѭ�������򷵻�i+1
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