#include <stdio.h>
#include <stdlib.h>

bool StringEqual(char* stra, char* strb)
{
    int i = 0;
    while (stra[i] != '\0' && strb[i] != '\0' && stra[i] == strb[i])
    {
        i++;
    }

    if (stra[i] == '\0' && strb[i] == '\0') { return true; }
    else { return false; }
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int findLUSlength(char* a, char* b) {
    if (StringEqual(a, b)) { return -1; }

    if (strlen(a) == strlen(b)) { return strlen(a); }
    else { return Max(strlen(a), strlen(b)); }
}


/**************************************************************************************************************/

bool StringEqual(char* stra, char* strb)
{
    int i = 0;
    while (stra[i] != '\0' && strb[i] != '\0' && stra[i] == strb[i])
    {
        i++;
    }

    if (stra[i] == '\0' && strb[i] == '\0') { return true; }
    return false;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int findLUSlength(char* a, char* b) {
    if (StringEqual(a, b)) { return -1; }

    return Max(strlen(a), strlen(b));
}

int main()
{


	system("pause");

	return 0;
}