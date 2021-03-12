#include <stdio.h>
#include <assert.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int minSubArrayLen(int target, int* nums, int numsSize) {
    int res = 0;
    //int resSize = 0;
    int resSize = numsSize + 1;
    int tmpi = 0, tmpj = 0;

    while (tmpi < numsSize)
    {
        res += nums[tmpi++];
        //resSize++;
        while (res >= target)
        {
            resSize = min(resSize, tmpi - tmpj);
            res -= nums[tmpj++];
            //resSize--;
        }
    }

    if (resSize > numsSize){return 0;}

    else{return resSize;}

}

int main()
{
	return 0;
}