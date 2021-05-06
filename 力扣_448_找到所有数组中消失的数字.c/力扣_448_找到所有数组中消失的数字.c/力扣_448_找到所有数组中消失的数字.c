#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)calloc(numsSize, sizeof(int));
    assert(arr);
    //int size = 0;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) { arr[nums[i] - 1]++; }

    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] == 0) //{size++;}
        {
            (*returnSize)++;
        }
    }

    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    assert(res);
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] == 0) { res[j++] = i + 1; }
    }

    return res;
}

int main()
{
	return 0;
}