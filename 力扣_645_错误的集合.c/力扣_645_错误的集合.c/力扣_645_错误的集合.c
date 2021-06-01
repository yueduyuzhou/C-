#include <stdio.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 2);
    assert(res);
    int* arr = (int*)calloc(numsSize, sizeof(int));
    assert(arr);
    //遍历数组，记录各元素出现的次数
    for (int i = 0; i < numsSize; i++) { arr[nums[i] - 1]++; }
    //遍历arr找出错误和没有出现的元素
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] == 2) { res[0] = i + 1; }
        else if (arr[i] == 0) { res[1] = i + 1; }
    }

    *returnSize = 2;
    return res;
}

int main()
{
	return 0;
}