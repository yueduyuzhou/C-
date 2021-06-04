#include <stdio.h>
#include <stdbool.h>

bool isNotDecrease(int* nums, int numsSize)
{
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i - 1] > nums[i]) { return false; }
    }
    return true;
}

bool checkPossibility(int* nums, int numsSize) {
    //遍历数组
    for (int i = 0; i < numsSize - 1; i++)
    {
        //保存当前元素值和下一个元素值
        int frontnum = nums[i];
        int backnum = nums[i + 1];

        if (frontnum > backnum)
        {
            //若当前元素值大于下一个元素值,使nums[i]=nums[i+1],判断改变后是否符合题意
            nums[i] = backnum;
            if (isNotDecrease(nums, numsSize)) { return true; }

            //前一种不符合,恢复原数组,使nums[i+1]=nums[i],判断改变后是否符合题意
            nums[i] = frontnum;
            nums[i + 1] = frontnum;
            return isNotDecrease(nums, numsSize);
        }
    }
    //出循环表示数组已经符合题意,直接返回true
    return true;
}

int main()
{

	return 0;
}