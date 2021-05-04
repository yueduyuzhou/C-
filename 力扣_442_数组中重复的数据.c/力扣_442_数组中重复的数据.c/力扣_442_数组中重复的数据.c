#include <stdio.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)calloc(numsSize, sizeof(int));
    assert(arr);
    int size = 0;

    for (int i = 0; i < numsSize; i++) { arr[nums[i] - 1]++; }

    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] == 2) { size++; }
    }

    int* res = (int*)malloc(sizeof(int) * size);
    assert(res);
    int j = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] == 2) { res[j++] = i + 1; }
    }

    *returnSize = size;
    return res;
}

/***************************************************************************/
//�Ż���
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    //%numsSize��Ϊ�˷�ֹԽ�����
    for (int i = 0; i < numsSize; i++)
    {
        nums[(nums[i] - 1) % numsSize] += numsSize;
    }
    //*returnSize����Ҫ��ʼ��
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        //>2*numsSize��ʾ���ִ�������2
        if (nums[i] > 2 * numsSize)
        {
            (*returnSize)++;
            nums[(*returnSize) - 1] = i + 1;
        }
    }

    return nums;
}
int main()
{
	return 0;
}