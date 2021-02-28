#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int str1 = m - 1;
    int str2 = n - 1;
    int size = nums1Size - 1;

    //从两个数组的最后一个元素开始比较大的放入nums1的后位置往前，当有一个数组比较完所有元素时跳出循环
    while (str1 >= 0 && str2 >= 0)
    {
        if (nums1[str1] >= nums2[str2])
            nums1[size--] = nums1[str1--];
        else
            nums1[size--] = nums2[str2--];
    }

    //将有剩下未比较元素的数组余下元素全部依次放入nums1余下位置
    if (str1 < 0)
    {
        while (str2 >= 0)
            nums1[size--] = nums2[str2--];
    }
    else if (str2 < 0)
    {
        while (str1 >= 0)
            nums1[size--] = nums1[str1--];
    }

}

int main()
{
    int nums1[6] = { 1,2,3,0,0,0 };
    int nums2[3] = { 2,5,6 };
    merge(nums1, 6, 3, nums2, 3, 3);

    for (int i = 0; i < 6; i++)
        printf("%d ", nums1[i]);

	return 0;
}