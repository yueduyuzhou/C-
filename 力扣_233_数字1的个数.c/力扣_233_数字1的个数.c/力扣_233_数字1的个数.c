#include <stdio.h>
#include <stdlib.h>

//暴力解，直接根据过程计1的个数
/*char* itoa(int num)
{
    char* num_str = (char*)malloc(sizeof(char) * 9);
    if (!num_str) { return NULL; }

    int index_num_str = 0;
    while (num)
    {
        num_str[index_num_str++] = num % 10 + '0';
        num /= 10;
    }
    num_str[index_num_str] = '\0';
    int left = 0, right = index_num_str - 1;
    while (left < right)
    {
        char tmp = num_str[left];
        num_str[left] = num_str[right];
        num_str[right] = tmp;
        left++, right--;
    }

    return num_str;
}

int countDigitOne(int n) {
    int res_count = 0;
    for (int i = 1; i <= n; i++)
    {
        char* ch = itoa(i);
        //int ch_len = strlen(ch);
        int j = 0;
        while (ch[j])
        {
            if (ch[j] == '1') { res_count++; }
            j++;
        }
    }

    return res_count;
}
*/
/**********************************************************************************************************/

long long my_max(long long a, long long b) { return a > b ? a : b; }
long long my_min(long long a, long long b) { return a > b ? b : a; }

int countDigitOne(int n) {
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + my_min(my_max(n % divider - i + 1, 0LL), i);
        //printf("%d", countr);
    }
    return countr;
}

/**********************************************************************************************************/


int main()
{
    countDigitOne(13);
	return 0;
}