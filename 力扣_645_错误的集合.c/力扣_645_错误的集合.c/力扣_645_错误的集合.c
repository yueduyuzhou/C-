#include <stdio.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 2);
    assert(res);
    int* arr = (int*)calloc(numsSize, sizeof(int));
    assert(arr);
    //�������飬��¼��Ԫ�س��ֵĴ���
    for (int i = 0; i < numsSize; i++) { arr[nums[i] - 1]++; }
    //����arr�ҳ������û�г��ֵ�Ԫ��
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] == 2) { res[0] = i + 1; }
        else if (arr[i] == 0) { res[1] = i + 1; }
    }

    *returnSize = 2;
    return res;
}

int main()
{
	return 0;
}