#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    if (numsSize == 0) { return 0; }

    int tmp = 0;
    int max = 0;

    for (int i = 0; i < numsSize; i++)
    {
        while (i < numsSize && nums[i] == 1) { tmp++, i++; }
        max = Max(max, tmp);
        tmp = 0;
    }

    return max;
}

/***************************************************************************************************************/

int Max (int a, int b)
{
    return a > b ? a : b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
    if (numsSize == 0) {return 0;}
    
    int tmp = 0;
    int max = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1) {tmp++;}
        else {tmp = 0;}
        max = Max (max, tmp);
    }

    return max;
}

int main()
{
    return 0;
}