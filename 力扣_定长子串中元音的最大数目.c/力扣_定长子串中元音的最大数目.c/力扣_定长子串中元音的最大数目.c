#include <stdio.h>
#include <stdbool.h>
bool searchVow(char ch)
{
    //char vow[5] = {'a', 'e', 'i', 'o', 'u'};
    //int i = 0;
    //while (i < 5)
    //{
    //使用下面这种方法，效率比while快
    //详见力扣提交结果
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    //}
    return false;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxVowels(char* s, int k) {
    int head = 0, tail = 0;
    int res = 0, tmp = 0;

    //窗口覆盖前k个字母并计算其中元音字母的个数
    while (tail < k)
    {
        res += (int)searchVow(s[tail++]);
    }
    //记录当前res的值，方便下面比较
    tmp = res;
    while (s[tail] != NULL)
    {
        tmp += (int)searchVow(s[tail++]);
        tmp -= (int)searchVow(s[head++]);
        res = max(tmp, res);
    }
    return res;
}

int main()
{
	return 0;
}