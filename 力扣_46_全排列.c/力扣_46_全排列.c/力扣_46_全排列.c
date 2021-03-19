#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//int resSize = 0;
//求全排列的排列数量
int getMaxarrangement(int numsSize)
{
    int tmp = 1;
    for (int i = 2; i <= numsSize; i++)
    {
        tmp *= i;
    }
    return tmp;
}

void BackTrack(int* nums, int numsSize, int** res, int* pass, bool* yetnum, int index, int* resSize)
{
    if (index == numsSize)
    {
        res[*resSize] = (int*)malloc(sizeof(int) * numsSize);
        assert(res[*resSize]);
        memcpy(res[(*resSize)++], pass, sizeof(int) * numsSize);
        //resSize++;
        //yetnum[] = false;
        //index--;
        return;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (yetnum[i] == true) { continue; }

        pass[index] = nums[i];
        yetnum[i] = true;
        //递归
        BackTrack(nums, numsSize, res, pass, yetnum, index + 1, resSize);
        //回撤时yetnum状态返回
        yetnum[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = NULL;
    int* pass = NULL;
    int     index = 0, resSize = 0;
    bool* yetnum = NULL;
    int iMax = getMaxarrangement(numsSize);

    res = (int**)malloc(sizeof(int*) * iMax);
    assert(res);
    pass = (int*)malloc(sizeof(int) * numsSize);
    assert(pass);
    yetnum = (bool*)malloc(sizeof(bool) * numsSize);
    assert(yetnum);
    memset(yetnum, 0, sizeof(bool) * numsSize);

    BackTrack(nums, numsSize, res, pass, yetnum, 0, &resSize);

    *returnSize = iMax;
    *returnColumnSizes = (int*)malloc(sizeof(int) * iMax);
    assert(returnColumnSizes);
    for (int i = 0; i < iMax; i++) { (*returnColumnSizes)[i] = numsSize; }

    return res;
}

int main()
{
    system("pause");
    return 0;
}