#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <stdlib.h>
#include <assert.h>

void Reverse_string(char* s)
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;

        left++, right--;
    }
}

char* licenseKeyFormatting(char* s, int k) {
    int len = strlen(s);
    int index_res = 0;
    int index_s = len - 1;
    int count = 0;
    //����һ���¿ռ䣨strlen+1��
    char* res = (char*)malloc(sizeof(char) * (len * 2));
    assert(res);
    //�¿ռ�ָ��Ӵ�ǰ�����ߣ� sָ��Ӻ���ǰ��
    while (index_s >= 0)
    {
        //��ǰ���������ַ�����k��������'-'������Сд��ĸת��λ��д��ĸ�����������ַ���k��ʱ���¿ռ��һ��'-'
        if (count == k)
        {
            count = 0;
            while (index_s >= 0 && s[index_s] == '-') { index_s--; }
            if (index_s >= 0) { res[index_res++] = '-'; }
        }
        else if ((s[index_s] >= '0' && s[index_s] <= '9') || (s[index_s] >= 'A' && s[index_s] <= 'Z'))
        {
            res[index_res++] = s[index_s--];
            count++;
        }
        else if (s[index_s] >= 'a' && s[index_s] <= 'z')
        {
            res[index_res++] = s[index_s--] - 32;
            count++;
        }
        else
        {
            index_s--;
        }
    }
    res[index_res] = '\0';

    Reverse_string(res);

    return res;
}

/****************************************************************************************************************************/
int main()
{

    licenseKeyFormatting("2-4A0r7-4k", 3);

    system("pause");

    return 0;
}