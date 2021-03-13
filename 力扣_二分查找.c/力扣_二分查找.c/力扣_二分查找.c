#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    //�õ�һ����ֹԽ�����
    int mid = left + (right - left) / 2;
    //int mid = (left + right) / 2;
    if (numsSize == 1 && nums[0] == target)
    {
        return 0;
    }

    //���ֲ��ҹ��̣���target����������ڣ��ڳ�ѭ��ǰ���ҵ�
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