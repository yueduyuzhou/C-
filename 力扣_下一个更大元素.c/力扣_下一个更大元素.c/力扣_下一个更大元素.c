#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//    if (!nums1Size)
//        return NULL;
//
//    int stack1[4];
//    int arr[3];
//    int arri = 0;
//    int top = 0;
//
//    while (top < nums2Size)
//    {
//        stack1[top] = nums2[top];
//        top++;
//    }
//    top -= 1;
//
//    while (arri < nums1Size)
//    {
//        int tmp = nums1[arri];
//        int flag = 0;
//        while (tmp != nums2[top])
//        {
//            if (tmp < nums2[top])
//            {
//                flag = 1;
//                arr[arri] = nums2[top];
//            }
//            top--;
//        }
//        if (flag == 0)
//            arr[arri] = -1;
//        arri++;
//        top = nums2Size - 1;
//    }
//
//    *returnSize = nums1Size - 1;
//    return arr;
//}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (!nums1Size)
        return NULL;

    int* stack1 = (int*)malloc(sizeof(int) * nums2Size);
    int* arr = (int*)malloc(sizeof(int) * nums1Size);
    int arri = 0;
    int top = 0;

    while (top < nums2Size)
    {
        stack1[top] = nums2[top];
        top++;
    }
    top -= 1;

    while (arri < nums1Size)
    {
        int tmp = nums1[arri];
        int flag = 0;
        while (tmp != nums2[top])
        {
            if (tmp < nums2[top])
            {
                flag = 1;
                arr[arri] = nums2[top];
            }
            top--;
        }
        if (flag == 0)
            arr[arri] = -1;
        arri++;
        top = nums2Size - 1;
    }

    *returnSize = nums1Size;
    free(stack1);
    stack1 = NULL;
    return arr;
}

int mian()
{
    int nums1[] = { 4,1,2 };
    int nums2[] = { 1,3,4,2 };
    int returnsize = 0;
    int* arr = nextGreaterElement(nums1, 3, nums2, 4, &returnsize);

	return 0;
}