#include <stdio.h>

/******************************************************************/
//while (front < numsSize) {
//    while (front < rear)
//    {
//        if (nums[front] > nums[rear])
//        {
//            Swap(nums + front, nums + rear);
//            break;
//        }
//        else { front++; }
//    }
//    front = 0;
//    rear++;
//}
/******************************************************************/

//int findKthLargest(int* nums, int numsSize, int k) {
//    if (numsSize == 0)
//        return 0;
//    //int* nums2 = (int*)malloc(sizeof(int) * numsSize);
//    //assert(nums2);
//    int tmp1 = 0, tmp2 = 0;
//
//    for (tmp1 = 1; tmp1 < numsSize; tmp1++)
//    {
//        for (tmp2 = tmp1 - 1; tmp2 >= 0; tmp2--)
//        {
//            int tmp = nums[tmp1];
//            if (tmp2 == 0)
//            {
//                if (nums[0] > tmp)
//                {
//                    nums[1] = nums[0];
//                    nums[0] = tmp;
//                }
//                else
//                {
//                    nums[1] = tmp;
//                }
//                break;
//            }
//
//            if (nums[tmp2] > tmp)
//            {
//                nums[tmp2 + 1] = nums[tmp2];
//            }
//            else
//            {
//                nums[tmp2 + 1] = tmp;
//                break;
//            }
//        }
//    }
//
//    return nums[numsSize - k];
//}

int main ()
{
    int nums[6] = { 3,2,1,5,6,4 };
    int tmp1 = 0, tmp2 = 0;
    int numsSize = 6, k = 2;

    for (tmp1 = 1; tmp1 < numsSize; tmp1++)
    {
        int tmp = nums[tmp1];
        for (tmp2 = tmp1 - 1; tmp2 >= 0; tmp2--)
        {
            if (tmp2 == 0)
            {
                if (nums[0] > tmp)
                {
                    nums[1] = nums[0];
                    nums[0] = tmp;
                }
                else
                {
                    nums[1] = tmp;
                }
                break;
            }

            if (nums[tmp2] > tmp)
            {
                nums[tmp2 + 1] = nums[tmp2];
            }
            else
            {
                nums[tmp2 + 1] = tmp;
                break;
            }
        }
    }
    //int num = findKthLargest(arr, 6, 2);
	return 0;
}