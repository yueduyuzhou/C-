#include <stdio.h>
#include <stdbool.h>

bool detectCapitalUse(char* word) {
    char* ch = word;

    int tmp = (int)((*ch) - 'A');
    //����ĸ��д
    if (tmp >= 0 && tmp < 26)
    {
        ch++;
        tmp = (int)((*ch) - 'A');
        //�ڶ�����ĸ�Ǵ�д
        if (*ch != '\0' && tmp >= 0 && tmp < 26)
        {
            while (*ch != '\0')
            {
                if (tmp >= 32 && tmp < 58) { return false; }

                ch++;
                tmp = (int)((*ch) - 'A');
            }
        }
        else if (*ch != '\0' && tmp >= 32 && tmp < 58)  //�ڶ�����ĸ��Сд
        {
            while (*ch != '\0')
            {
                if (tmp >= 0 && tmp < 26) { return false; }

                ch++;
                tmp = (int)((*ch) - 'A');
            }
        }
    }
    else if (tmp >= 32 && tmp < 58)  //����ĸСд
    {
        while (*ch != '\0')
        {
            if (tmp >= 0 && tmp < 26) { return false; }

            ch++;
            tmp = (int)((*ch) - 'A');
        }
    }

    return true;
}

int main()
{

    char* a = "AMAzON";
    detectCapitalUse(a);
	return 0;
}