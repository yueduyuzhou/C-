#include <stdio.h>
#include <stdbool.h>
bool searchVow(char ch)
{
    //char vow[5] = {'a', 'e', 'i', 'o', 'u'};
    //int i = 0;
    //while (i < 5)
    //{
    //ʹ���������ַ�����Ч�ʱ�while��
    //��������ύ���
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

    //���ڸ���ǰk����ĸ����������Ԫ����ĸ�ĸ���
    while (tail < k)
    {
        res += (int)searchVow(s[tail++]);
    }
    //��¼��ǰres��ֵ����������Ƚ�
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