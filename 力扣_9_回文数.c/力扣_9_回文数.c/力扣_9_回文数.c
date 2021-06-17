#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* ch)
{
    int left = 0;
    int right = strlen(ch) - 1;
    /*if (ch[0] == '-')
    {
        left++;
    }*/

    while (left < right)
    {
        char tmp = ch[left];
        ch[left] = ch[right];
        ch[right] = tmp;

        left++;
        right--;
    }
}

char* my_itoa(int x)
{
    char* res = (char*)malloc(sizeof(char) * 12);
    int i = 0;

    if (x < 0) { res[i++] = '-'; }

    while (x)
    {
        res[i++] = x % 10 + '0';
        x /= 10;
    }
    res[i] = '\0';

    reverse(res);
    return res;
}

bool isPalindrome(int x) {
    char* num_str = my_itoa(x);
    int left = 0;
    int right = strlen(num_str) - 1;
    while (left < right)
    {
        if (num_str[left] != num_str[right]) { break; }

        left++;
        right--;
    }

    if (left >= right) { return true; }
    return false;
}

int main()
{
    isPalindrome(-121);

	exit(0);
}