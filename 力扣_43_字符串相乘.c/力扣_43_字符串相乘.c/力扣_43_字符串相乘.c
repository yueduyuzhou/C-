#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* itoa_num(int num, int len_1, int len_2)
{
    char* res = malloc(sizeof(char) * (len_1 + len_2 + 1));
    int i = 0;

    while (num > 0)
    {
        res[i++] = num % 10 + '0';
        num /= 10;
    }
    res[i] = '\0';

    return res;
}

void Reverce(char* ch)
{
    int left = 0;
    int right = strlen(ch) - 1;

    while (left < right)
    {
        char tmp = ch[left];
        ch[left] = ch[right];
        ch[right] = tmp;

        left++, right--;
    }
}

char* multiply(char* num1, char* num2) {
    int num_1 = atoi(num1);
    int num_2 = atoi(num2);
    if (num_1 == 0 || num_2 == 0) { return "0\0"; }

    int res_num = num_1 * num_2;

    char* res = itoa_num(res_num, strlen(num1), strlen(num2));
    Reverce(res);

    return res;
}

/********************************************************************************************************************/

void Reverse(char* ch)
{
    int left = 0;
    int right = strlen(ch) - 1;

    while (left < right)
    {
        char tmp = ch[left];
        ch[left] = ch[right];
        ch[right] = tmp;
        left++, right--;
    }
}

char* addStrings(char* num1, char* num2) {
    int len_1 = strlen(num1);
    int len_2 = strlen(num2);
    int len = len_1 > len_2 ? len_1 : len_2;
    int flag = 0;
    int i = 0;
    char* res = malloc(sizeof(char) * (len + 2));

    len_1--, len_2--;
    while (len_1 >= 0 && len_2 >= 0)
    {
        res[i] = num1[len_1] + num2[len_2] - '0' + flag;
        if (res[i] >= ':')
        {
            flag = 1;
            res[i] = res[i] - 10;
        }
        else
        {
            flag = 0;
        }
        i++;
        len_1--, len_2--;
    }

    while (len_1 >= 0)
    {
        res[i] = num1[len_1] + flag;
        if (res[i] == ':')
        {
            flag = 1;
            res[i] = res[i] - 10;
        }
        else
        {
            flag = 0;
        }
        i++;
        len_1--;
    }
    while (len_2 >= 0)
    {
        res[i] = num2[len_2] + flag;
        if (res[i] == ':')
        {
            flag = 1;
            res[i] = res[i] - 10;
        }
        else
        {
            flag = 0;
        }
        i++;
        len_2--;
    }

    if (flag == 1) { res[i++] = '1'; }
    res[i] = '\0';

    Reverse(res);

    return res;
}

char* multiply(char* num1, char* num2) {
    int m = strlen(num1), n = strlen(num2);
    char* ans = malloc(sizeof(char) * 2);
    ans[0] = '0', ans[1] = 0;
    if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) {
        return ans;
    }
    for (int i = n - 1; i >= 0; i--) {
        char* curr = malloc(sizeof(char) * (n + m + 5));
        int currLen = 0;
        int add = 0;
        for (int j = n - 1; j > i; j--) {
            curr[currLen++] = 0;
        }
        int y = num2[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            int x = num1[j] - '0';
            int product = x * y + add;
            curr[currLen++] = product % 10;
            add = product / 10;
        }
        while (add != 0) {
            curr[currLen++] = add % 10;
            add /= 10;
        }
        for (int i = 0; i < currLen / 2; i++) {
            char t = curr[i];
            curr[i] = curr[currLen - 1 - i];
            curr[currLen - 1 - i] = t;
        }
        for (int i = 0; i < currLen; i++) {
            curr[i] += '0';
        }
        curr[currLen++] = 0;
        char* tmp = addStrings(ans, curr);
        free(ans), free(curr);
        ans = tmp;
    }
    return ans;
}


/********************************************************************************************************************/

char* multiply(char* num1, char* num2) {
    int m = strlen(num1), n = strlen(num2);
    char* ans = malloc(sizeof(char) * (m + n + 3));
    memset(ans, 0, sizeof(char) * (m + n + 3));
    if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) {
        ans[0] = '0', ans[1] = 0;
        return ans;
    }
    int* ansArr = malloc(sizeof(int) * (m + n + 3));
    memset(ansArr, 0, sizeof(int) * (m + n + 3));
    for (int i = m - 1; i >= 0; i--) {
        int x = num1[i] - '0';
        for (int j = n - 1; j >= 0; j--) {
            int y = num2[j] - '0';
            ansArr[i + j + 1] += x * y;
        }
    }
    for (int i = m + n - 1; i > 0; i--) {
        ansArr[i - 1] += ansArr[i] / 10;
        ansArr[i] %= 10;
    }
    int index = ansArr[0] == 0 ? 1 : 0;
    int ansLen = 0;
    while (index < m + n) {
        ans[ansLen++] = ansArr[index];
        index++;
    }
    for (int i = 0; i < ansLen; i++) ans[i] += '0';
    return ans;
}

/********************************************************************************************************************/


int main()
{
    multiply("9", "9");


	system("pause");
	return 0;
}