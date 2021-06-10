#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char* ch)
{
    int left = 0;
    int right = strlen(ch) - 1;
    /*if (ch[0] == '-')
    {
        left++;
    }*/
    char* ch_reverse = (char*)malloc(sizeof(char) * (right + 2));
    strcpy(ch_reverse, ch);
    //printf ("%s_%s ", ch_reverse, ch);
    while (left < right)
    {
        char tmp = ch_reverse[left];
        ch_reverse[left] = ch_reverse[right];
        ch_reverse[right] = tmp;

        left++;
        right--;
    }

    //ch_reverse[strlen(ch)] = '\0';
    return ch_reverse;
}

char* my_itoa(int x)
{
    char* res = (char*)malloc(sizeof(char) * 12);
    int i = 0;

    //if (x < 0) { res[i++] = '-'; }

    while (x)
    {
        res[i++] = x % 10 + '0';
        x /= 10;
    }
    res[i] = '\0';
    char* tmp = res;
    res = reverse(tmp);
    free(tmp);
    tmp = NULL;
    return res;
}

long long my_atoll(char* ch)
{
    long long num_ch = 0;
    int i = 0;
    while (ch[i] != '\0')
    {
        num_ch = num_ch * 10 + (ch[i] - '0');
        i++;
    }

    return num_ch;
}

int largestPalindrome(int n) {
    if (n == 1) { return 9; }
    //求上下界
    int upper = (int)pow(10, n) - 1;
    int lower = (int)pow(10, n - 1);
    //fprintf (stdout, "%d_%d ", upper, lower);

    for (int i = upper; i >= lower; i--)
    {
        //fprintf(stdout, "%d ", i);

        char* str_i = my_itoa(i);
        char* reverse_str_i = reverse(str_i);

        char* str_reverse = (char*)malloc(strlen(str_i) + strlen(reverse_str_i) + 2);
        //printf ("%d", (strlen(str_i) + strlen(reverse_str_i) + 1));
        //strcat(str_reverse, str_i);
        //strcat(str_reverse, reverse_str_i);
        int x = 0;
        int y = 0;
        while (str_i[y] != '\0')
        {
            str_reverse[x++] = str_i[y++];
        }
        y = 0;
        while (reverse_str_i[y] != '\0')
        {
            str_reverse[x++] = reverse_str_i[y++];
        }
        str_reverse[x] = '\0';

        long long product = my_atoll(str_reverse);
        //printf(" %ld ", product);
        long long j = (long long)upper;
        for (; j * j >= product; j--)
        {
            if (product % j == 0) { return product % 1337; }
        }
    }

    return -1;
}




int main()
{
    largestPalindrome(2);

    return 0;
}