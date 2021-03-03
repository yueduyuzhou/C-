#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    //注意判断输入的数组为空的情况，否则出while后的语句会导致越界访问(内存问题)
    if (numsSize == 0)
        return 0;
    int prev = 0;
    int cur = 1;
    int dst = 0;
    //用cur作为边界，赋值nums[cur]越界
    while (cur < numsSize)
    {
        if (nums[prev] == nums[cur])
            prev++, cur++;
        else if (nums[prev] != nums[cur])
        {
            nums[dst] = nums[prev];
            dst++, prev++, cur++;
        }
    }
    //出while循环后，数组最后一个元素可能需要放入
    nums[dst] = nums[prev];
    dst++;
    return dst;
}

int main()
{
    int nums[] = { 1,1,2,2,2,3 };
    int size = removeDuplicates(nums, 6);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
	return 0;
}