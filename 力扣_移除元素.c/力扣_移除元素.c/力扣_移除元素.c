#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int src = 0;
    int dst = 0;
    while (src < numsSize)
    {
        if (nums[src] != val)
            nums[dst++] = nums[src++];
        else
            src++;
    }
    return dst;
}

int main()
{
    int nums[4] = { 3,2,2,3 };
    int size = removeElement(nums, 4, 3);
    printf("\n\n[");
    for (int i = 0; i < size; i++)
        printf("%d,", nums[i]);
    printf("]\n\n");
    //printf("\n\n[%d, %d]\n\n", nums[0], nums[1]);
    return 0;
}