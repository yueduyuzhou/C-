#include <stdio.h>

/*****************************************
*                                        *                                        
*          方法1.分治算法                *
*                                        *
******************************************/

int Max(int a, int b, int c)
{
    return c > (a > b ? a : b) ? c : (a > b ? a : b);
}

int getCrossMax(int* nums, int left, int right)
{
    int mid = left + (right - left) / 2;
    int i = 0;

    //从中间向<左>开始循环，获得最大连续子数组
    int leftSum = nums[mid];
    int leftMax = nums[mid];
    for (i = mid - 1; i >= 0; i--)
    {
        leftSum += nums[i];
        leftMax = (leftSum > leftMax ? leftSum : leftMax);
    }

    //从中间向<右>开始循环，获得最大连续子数组
    int rightSum = nums[mid + 1];
    int rightMax = nums[mid + 1];
    for (i = mid + 2; i <= right; i++)
    {
        rightSum += nums[i];
        rightMax = (rightSum > rightMax ? rightSum : rightMax);
    }

    //返回左右子数组的和
    return (rightMax + leftMax);
}

int getMaxSubarr(int* nums, int left, int right)
{
    //返回条件:>已分到不可再分
    if (left == right) { return nums[left]; }

    int mid = left + (right - left) / 2;

    //分别获得<左><右><中间>最大连续子数组和
    int leftMax = getMaxSubarr(nums, left, mid);
    int rightMax = getMaxSubarr(nums, mid + 1, right);
    int crossMax = getCrossMax(nums, left, right);

    //三者取最大返回
    return Max(leftMax, rightMax, crossMax);
}


int maxSubArray(int* nums, int numsSize) {
    //if (numsSize == 1) {return nums[0];}
    //获得数组的最大连续子数组
    return getMaxSubarr(nums, 0, numsSize - 1);
}

int main()
{
	return 0;
}