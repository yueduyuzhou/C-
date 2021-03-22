#include <stdio.h>

//µ›πÈÀ„∑®
int  getMajority(int* nums, int left, int right)
{
    if (left == right) { return nums[left]; }

    int mid = left + (right - left) / 2;

    int leftMajority = getMajority(nums, left, mid);
    int rightMajority = getMajority(nums, mid + 1, right);

    if (leftMajority == rightMajority) { return leftMajority; }

    int leftcount = 0;
    int rightcount = 0;

    for (int i = left; i <= right; i++)
    {
        if (nums[i] == leftMajority) { leftcount++; }
        else if (nums[i] == rightMajority) { rightcount++; }
    }

    if (leftcount > rightcount) { return leftMajority; }
    else { return rightMajority; }
}

int majorityElement(int* nums, int numsSize) {
    return getMajority(nums, 0, numsSize - 1);
}

int main()
{
	return 0;
}