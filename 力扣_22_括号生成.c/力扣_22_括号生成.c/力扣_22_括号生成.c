#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backTracking(int n, int* returnSize, char** result, int left, int right, char* str, int index)
{
    //if (right > left) {return;}
    //当index等于2n时，说明所有括号都以加入str
    if (index == 2 * n)
    {
        //先给对应的result开辟一个存放字符串数组的指针
        result[(*returnSize)] = (char*)calloc((2 * n + 1), sizeof(char));
        strcpy(result[(*returnSize)++], str);
        return;
    }
    
    //left小于n，还有左括号没加入str
    if (left < n)
    {
        str[index] = '(';
        backTracking(n, returnSize, result, left + 1, right, str, index + 1);
    }
    //right小于left，还有右括号可以加入
    if (right < left)
    {
        str[index] = ')';
        backTracking(n, returnSize, result, left, right + 1, str, index + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    //1430时卡特兰数
    char** result = (char**)malloc(sizeof(char*) * 1430);
    assert(result);
    //2n是左右括号相加的所有字符数，+1表示以/0结尾
    char* str = (char*)calloc((2 * n + 1), sizeof(char));
    assert(str);

    *returnSize = 0;
    //每次条件符合回到这里，都会重新开始生成括号序列
    backTracking(n, returnSize, result, 0, 0, str, 0);

    return result;
}

int main()
{
	return 0;
}