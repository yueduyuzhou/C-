#include <stdio.h>

/***********************************************************************************************************/

//有漏洞：相同子串会重复计算
int findSubstringInWraproundString(char* p) {
    int res = 0;
    int hash[26] = { 0 };

    int i = 0;
    while (p[i] != '\0')
    {
        if (hash[p[i] - 'a']++ == 0)
        {
            res++;
            //printf ("%d ",res);
        }


        int j = i;
        while (p[j + 1] != '\0')
        {
            int flag = 0;
            if (p[j + 1] == ((p[j] - 97 + 1) % 26) + 97)
            {
                res++;
                flag = 1;
            }
            j++;
            if (flag == 0) { break; }
        }

        i++;
    }

    //for (i = 0; i < 26; i++)
    //{
    //    printf("%d ", hash[i]);
    //}

    return res;
}

/***********************************************************************************************************/

int max(int a, int b)
{
    return a > b ? a : b;
}

int findSubstringInWraproundString(char* p) {
    int n = strlen(p);
    if (n == 0)return 0;
    int tog[26] = { 0 };
    int ret = 0, cur = 1;
    //cur设置为1因为单独的一个字母也可以组成一个字符串
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1)cur++;
        //这里有个细节要注意因为可能出现wxyzabc这种情况，所要加上这个周期值，在除以26以防止越界
        else
            cur = 1;
        tog[p[i] - 'a'] = max(tog[p[i] - 'a'], cur);

    }

    for (int i = 0; i < 26; i++)
        ret += tog[i];

    return ret;
}

int main()
{

    char ch[6] = { 'a','b','a','a','b','\0' };
    findSubstringInWraproundString(ch);


	system("pause");

	return 0;
}