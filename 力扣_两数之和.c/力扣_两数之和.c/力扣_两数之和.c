#include <stdio.h>
#include <malloc.h>

//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    int sub1 = 0;
//    int sub2 = 0;
//    for (sub1 = 0; sub1 < numsSize - 1; sub1++)
//    {
//        for (sub2 = sub1 + 1; sub2 < numsSize; sub2++)
//        {
//            if (nums[sub1] + nums[sub2] == target)
//            {
//                returnSize[0] = sub1;
//                returnSize[1] = sub2;
//                return returnSize;
//            }
//        }
//    }
//}

//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    int sub1 = 0;
//    int sub2 = 0;
//    int arr[2] = { 0 };
//    for (sub1 = 0; sub1 < numsSize; sub1++)
//    {
//        for (sub2 = sub1 + 1; sub2 < numsSize; sub2++)
//        {
//            if (nums[sub1] + nums[sub2] == target)
//            {
//                arr[0] = sub1;
//                arr[1] = sub2;
//                returnSize = arr;
//                return returnSize;
//            }
//        }
//    }
//}

//nums指数组，numsSize指数组长度，target是目标值，returnSize指返回数组的大小
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int sub1 = 0;
    int sub2 = 0;
    int* arr = (int*)malloc(2 * sizeof(int));
    for (sub1 = 0; sub1 < numsSize - 1; sub1++)
    {
        for (sub2 = sub1 + 1; sub2 < numsSize; sub2++)
        {
            if (nums[sub1] + nums[sub2] == target)
            {
                arr[0] = sub1;
                arr[1] = sub2;
                *returnSize = 2;
                return arr;
            }
        }
    }
    *returnSize = 0;
    return 0;
}

int main()
{
    int nums[] = { 2,7,11,15 };
    int target = 26;
    int* returnSize = (int*)malloc(2 * sizeof(int));
    int* arr = (int*)malloc(2 * sizeof(int));
    arr = twoSum(nums, 4, target, returnSize);
    printf("\n\n[%d, %d]\n\n", arr[0], arr[1]);
    free(arr);
    free(returnSize);
    return 0;
}