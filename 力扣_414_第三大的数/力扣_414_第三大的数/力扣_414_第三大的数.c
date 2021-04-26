#include <stdio.h>

#define INT_MIN -2147483648

int thirdMax(int* nums, int numsSize) {
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;

    int tmp1 = nums[0];
    int tmp2 = nums[0];
    int tmp3 = nums[0];

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != tmp1)
        {
            if (tmp1 != tmp2) { tmp3 = nums[i]; }
            else { tmp2 = nums[i]; }
        }

        if (nums[i] > first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] < first && nums[i] > second)
        {
            third = second;
            second = nums[i];
        }
        else if (nums[i] < first && nums[i] < second && nums[i] > third)
        {
            third = nums[i];
        }

    }

    if (tmp1 == tmp3 || tmp2 == tmp3) { return first; }

    return third;
}

int main()
{
	return 0;
}