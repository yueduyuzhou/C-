#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    //用第一条防止越界访问
    int mid = left + (right - left) / 2;
    //int mid = (left + right) / 2;
    if (numsSize == 1 && nums[0] == target)
    {
        return 0;
    }

    //二分查找过程，若target在数组里存在，在出循环前会找到
    while (left <= right)
    {
        if (nums[mid] > target)
        {
            right = mid - 1;
            //mid = (left + right) / 2;
            mid = left + (right - left) / 2;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
            //mid = (left + right) / 2;
            mid = left + (right - left) / 2;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{

	return 0;
}