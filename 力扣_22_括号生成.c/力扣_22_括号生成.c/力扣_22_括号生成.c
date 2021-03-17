#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backTracking(int n, int* returnSize, char** result, int left, int right, char* str, int index)
{
    //if (right > left) {return;}
    //��index����2nʱ��˵���������Ŷ��Լ���str
    if (index == 2 * n)
    {
        //�ȸ���Ӧ��result����һ������ַ��������ָ��
        result[(*returnSize)] = (char*)calloc((2 * n + 1), sizeof(char));
        strcpy(result[(*returnSize)++], str);
        return;
    }
    
    //leftС��n������������û����str
    if (left < n)
    {
        str[index] = '(';
        backTracking(n, returnSize, result, left + 1, right, str, index + 1);
    }
    //rightС��left�����������ſ��Լ���
    if (right < left)
    {
        str[index] = ')';
        backTracking(n, returnSize, result, left, right + 1, str, index + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    //1430ʱ��������
    char** result = (char**)malloc(sizeof(char*) * 1430);
    assert(result);
    //2n������������ӵ������ַ�����+1��ʾ��/0��β
    char* str = (char*)calloc((2 * n + 1), sizeof(char));
    assert(str);

    *returnSize = 0;
    //ÿ���������ϻص�����������¿�ʼ������������
    backTracking(n, returnSize, result, 0, 0, str, 0);

    return result;
}

int main()
{
	return 0;
}