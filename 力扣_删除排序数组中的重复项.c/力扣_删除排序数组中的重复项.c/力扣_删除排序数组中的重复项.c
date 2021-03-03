#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    //ע���ж����������Ϊ�յ�����������while������ᵼ��Խ�����(�ڴ�����)
    if (numsSize == 0)
        return 0;
    int prev = 0;
    int cur = 1;
    int dst = 0;
    //��cur��Ϊ�߽磬��ֵnums[cur]Խ��
    while (cur < numsSize)
    {
        if (nums[prev] == nums[cur])
            prev++, cur++;
        else if (nums[prev] != nums[cur])
        {
            nums[dst] = nums[prev];
            dst++, prev++, cur++;
        }
    }
    //��whileѭ�����������һ��Ԫ�ؿ�����Ҫ����
    nums[dst] = nums[prev];
    dst++;
    return dst;
}

int main()
{
    int nums[] = { 1,1,2,2,2,3 };
    int size = removeDuplicates(nums, 6);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
	return 0;
}