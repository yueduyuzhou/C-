#include <stdio.h>
#include <stdlib.h>


//bug
char* my_itoa(int num)
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

int maximumSwap(int num) {
    //个位数，直接返回
    if (num / 10 == 0) { return num; }

    //转位字符串，方便查找
    char* num_str = my_itoa(num);

    int flag = 0;
    int index_num_str = 1;
    int max_index = 0;
    while (1)
    {
        while (num_str[index_num_str])
        {
            if (num_str[index_num_str] > num_str[max_index])
            {
                max_index = index_num_str;
            }
            index_num_str++;
        }

        if (max_index == flag) { flag++; max_index = flag; }
        
        if (max_index != flag || num_str[index_num_str] == '\0') { break; }

        index_num_str = max_index + 1;
    }

    printf("%d %d    ", flag, max_index);

    char tmp = num_str[flag];
    num_str[flag] = num_str[max_index];
    num_str[max_index] = tmp;

    return atoi(num_str);
}

int main()
{
    maximumSwap(9973);
	return 0;
}