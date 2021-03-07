#include <stdio.h>

//void rotate(int* nums, int numsSize, int k) {
//    if (numsSize == 1 || k == numsSize)
//        return;
//    if (k > numsSize)
//        k %= numsSize;
//
//    int a = k;
//    int arrtmp[a] = { 0 };
//    int tmp = numsSize - k;
//    int i = 0;
//    while (tmp < numsSize)
//        arrtmp[i++] = nums[tmp++];
//
//    tmp = numsSize - k - 1;
//    i = numsSize - 1;
//    while (tmp >= 0)
//        nums[i--] = nums[tmp--];
//
//    i = 0;
//    while (i < k)
//    {
//        nums[i] = arrtmp[i];
//        i++;
//    }
//}

//逆置
void reverse(int* nums, int left, int right) {
    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++, right--;
    }
}

//先逆置nums数组0到k-1的元素，再逆置k到最后一个元素，最后逆置整个数组，能得到需要的答案；
//空间复杂度：O(1)；
//时间复杂度：O(n)；
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 1 || k == numsSize)
        return;
    if (k > numsSize)
        k %= numsSize;
    
    //逆置三部分
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

int main()
{
    int nums[] = { 1,2,3,4,5,6,7 };
    rotate(nums, 7, 10);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", nums[i]);
    }
	return 0;
}