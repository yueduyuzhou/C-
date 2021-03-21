#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/****************************************************************************************************************************************/
//评论解
/*
int** res;
int resSize;
int* temp;
int tempSize;

void helper(int* nums, int numsSize, int** returnColumnSizes, int startindex) {

    res[resSize] = malloc(sizeof(int) * tempSize);
    memcpy(res[resSize], temp, sizeof(int) * tempSize);
    (*returnColumnSizes)[resSize++] = tempSize;

    for (int i = startindex; i < numsSize; i++) {
        temp[tempSize++] = nums[i];
        helper(nums, numsSize, returnColumnSizes, i + 1);
        tempSize--;
    }
}

// 画出来这个树状的解空间，可以看到解就是树上所有的节点，但由于集合跟顺序无关，因此选取的规则：不回头, 如何遍历整个空间树，用回溯
#define MAXSIZE  20000
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (!nums || !numsSize) return nums;

    res = (int**)malloc(sizeof(int*) * MAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAXSIZE);
    temp = (int*)malloc(sizeof(int) * numsSize);
    resSize = tempSize = 0;

    helper(nums, numsSize, returnColumnSizes, 0);
    *returnSize = resSize;
    return res;
}
*/
/**************************************************************************************************************************************************/
/*
void resultAdd(int** result, int* index, int* subset)
{
    //result[index] = (int*)calloc(length, sizeof(int));
    //assert(result[index]);
    result[(*index)++] = subset;
}

void subsetAdd(int* subset, int num, int* subsize)
{
    subset[(*subsize)] = num;
    (*subsize)++;
}

void backTracking(int* nums, int** result, int length, int* index, int* subset, int numsi, int subsize, int numsSize)
{
    if (subsize == length)
    {
        int* temp = (int*)malloc(sizeof(int) * length);
        assert(temp);
        memcpy(temp, subset, length);
        resultAdd(result, index, subset);
        return;
    }

    for (int i = numsi; i < numsSize; i++)
    {
        //subsize++;
        subsetAdd(subset, nums[i], &subsize);
        backTracking(nums, result, length, index, subset, i + 1, subsize, numsSize);
        subsize--;
    }
}

#define Max_Size 16400
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)calloc(Max_Size, sizeof(int*));
    assert(result);
    //把空先加入到result中
    int index = 0;
    resultAdd(result, returnSize, NULL);

    for (int i = 1; i < numsSize; i++)
    {
        backTracking(nums, result, i, returnSize, NULL, 0, 0, numsSize);
    }
    return result;
}
*/
/*********************************************************************************************************************************/

void dfs(int* nums, int numsSize, int** res, int* returnSize, int** returnColumnSizes, int* str, int depth, int startindex) {
    res[*returnSize] = (int*)malloc(depth * sizeof(int));
    memcpy(res[*returnSize], str, depth * sizeof(int));
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;
    for (int i = startindex; i < numsSize; i++) {
        str[depth] = nums[i];
        dfs(nums, numsSize, res, returnSize, returnColumnSizes, str, depth + 1, i + 1);
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** res = (int**)malloc(2000 * sizeof(int*));
    int* str = (int*)malloc(numsSize * sizeof(int));
    *returnColumnSizes = (int*)calloc(2000, sizeof(int));
    dfs(nums, numsSize, res, returnSize, returnColumnSizes, str, 0, 0);
    return res;
}

/*****************************************************************************************************************************************/

int* path = NULL;
int pathSize = 0;
int** res = NULL;
int resSize = 0;
int* resColSize = 0;

void dfs(int* nums, int numsSize, int index)
{
    int* tmp = (int*)calloc(pathSize, sizeof(int));
    assert(tmp);
    memcpy(tmp, path, pathSize * sizeof(int));

    res[resSize] = tmp;
    resColSize[resSize] = pathSize;
    resSize++;

    for (int i = index; i < numsSize; i++)
    {
        path[pathSize++] = nums[i];
        dfs(nums, numsSize, i + 1);
        pathSize--;
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    res = (int**)calloc(1 << numsSize, sizeof(int*));
    assert(res);
    path = (int*)calloc(1 << numsSize, sizeof(int));
    assert(path);
    resColSize = (int*)calloc(1 << numsSize, sizeof(int));
    assert(resColSize);
    pathSize = resSize = 0;

    dfs(nums, numsSize, 0);

    *returnSize = resSize;
    *returnColumnSizes = resColSize;

    return res;
}

int main()
{
    int nums[3] = { 1,2,3 };
    int returnSize = 0;
    int** returnColumnSizes = NULL;
    subsets(nums, 3, &returnSize, returnColumnSizes);
    return 0;
}