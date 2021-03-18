#include <stdio.h>

/*****************************************
*                                        *                                        
*          ����1.�����㷨                *
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

    //���м���<��>��ʼѭ��������������������
    int leftSum = nums[mid];
    int leftMax = nums[mid];
    for (i = mid - 1; i >= 0; i--)
    {
        leftSum += nums[i];
        leftMax = (leftSum > leftMax ? leftSum : leftMax);
    }

    //���м���<��>��ʼѭ��������������������
    int rightSum = nums[mid + 1];
    int rightMax = nums[mid + 1];
    for (i = mid + 2; i <= right; i++)
    {
        rightSum += nums[i];
        rightMax = (rightSum > rightMax ? rightSum : rightMax);
    }

    //��������������ĺ�
    return (rightMax + leftMax);
}

int getMaxSubarr(int* nums, int left, int right)
{
    //��������:>�ѷֵ������ٷ�
    if (left == right) { return nums[left]; }

    int mid = left + (right - left) / 2;

    //�ֱ���<��><��><�м�>��������������
    int leftMax = getMaxSubarr(nums, left, mid);
    int rightMax = getMaxSubarr(nums, mid + 1, right);
    int crossMax = getCrossMax(nums, left, right);

    //����ȡ��󷵻�
    return Max(leftMax, rightMax, crossMax);
}


int maxSubArray(int* nums, int numsSize) {
    //if (numsSize == 1) {return nums[0];}
    //���������������������
    return getMaxSubarr(nums, 0, numsSize - 1);
}

int main()
{
	return 0;
}