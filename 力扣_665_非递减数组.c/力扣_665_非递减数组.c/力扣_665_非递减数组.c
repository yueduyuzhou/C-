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
    //��������
    for (int i = 0; i < numsSize - 1; i++)
    {
        //���浱ǰԪ��ֵ����һ��Ԫ��ֵ
        int frontnum = nums[i];
        int backnum = nums[i + 1];

        if (frontnum > backnum)
        {
            //����ǰԪ��ֵ������һ��Ԫ��ֵ,ʹnums[i]=nums[i+1],�жϸı���Ƿ��������
            nums[i] = backnum;
            if (isNotDecrease(nums, numsSize)) { return true; }

            //ǰһ�ֲ�����,�ָ�ԭ����,ʹnums[i+1]=nums[i],�жϸı���Ƿ��������
            nums[i] = frontnum;
            nums[i + 1] = frontnum;
            return isNotDecrease(nums, numsSize);
        }
    }
    //��ѭ����ʾ�����Ѿ���������,ֱ�ӷ���true
    return true;
}

int main()
{

	return 0;
}