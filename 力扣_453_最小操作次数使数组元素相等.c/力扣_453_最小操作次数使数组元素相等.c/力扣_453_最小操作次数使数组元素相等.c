#include <stdio.h>
/**************************************************************************************/
//ԭ��Ŀ����n-1����+1����
//ת��Ϊ��1����-1����
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