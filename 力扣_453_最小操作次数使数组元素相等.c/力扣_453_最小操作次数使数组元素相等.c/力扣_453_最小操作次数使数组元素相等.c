#include <stdio.h>
/**************************************************************************************/
//原题目是求n-1个数+1次数
//转化为求1个数-1次数
int minMoves(int* nums, int numsSize) {
    int tmp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[0] > nums[i])
        {
            tmp = nums[i];
            nums[i] = nums[0];
            nums[0] = tmp;
        }
    }

    tmp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        tmp += nums[i] - nums[0];
    }

    return tmp;
}

int main()
{

	return 0;
}