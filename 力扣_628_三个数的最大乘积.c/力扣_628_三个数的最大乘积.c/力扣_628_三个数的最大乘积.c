#include <stdio.h>

int cmp(int* a, int* b)
{
    return *a - *b;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    return Max(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]);
}

int main()
{

	return 0;
}