#include <stdio.h>

/**********************************************************************************************************************/
//时间复杂度太高，力扣超出时间限制

//每调用一次，就顺时针旋转一位
void Rotateone(int* nums, int numsSize)
{
    int tmp = nums[numsSize - 1];

    int i = numsSize - 2;
    while (i >= 0)
    {
        nums[i + 1] = nums[i];
        i--;
    }

    nums[0] = tmp;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int maxRotateFunction(int* nums, int numsSize) {
    //if(numsSize == 0) {return 0;}

    if (numsSize == 1) { return 0; }

    int res = INT_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        int tmp = 0;
        for (int j = 1; j < numsSize; j++)
        {
            //printf ("%d ",nums[j]);
            tmp += (j * nums[j]);
        }
        printf("%d ", tmp);
        res = Max(res, tmp);
        Rotateone(nums, numsSize);
    }

    return res;
}

/***********************************************************************************************************************/
int maxRotateFunction(int* nums, int numsSize) {
    long sum = 0;
    int f1 = 0;
    int f2 = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        f1 += i * nums[i];
    }

    int res = f1;
    for (int i = 1; i < numsSize; i++)
    {
        f2 = f1 + sum - (long)numsSize * nums[numsSize - i];
        if (f2 > res) { res = f2; }
        f1 = f2;
    }

    return res;
}


int main()
{


	system("pause");

	return 0;
}