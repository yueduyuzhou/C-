#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int n = 0, m = 0;
    for (n = 0; n < numsSize; n++)    //�ӵ�0����ʼ�Ƚ�
    {
        for (m = n + 1; m < numsSize; m++)    //�ӵ�n + 1����ʼ���n����ʼ�Ƚ�
        {
            if (nums[n] + nums[m] == target)    //�ж�
            {
                *returnSize = n;    //�ı���������ֵ������һ���±�ĵ�ַ
                return &m;    //������һ���±�
            }
        }
    }
}

int main()
{
    int numsSize = 0,i = 0;
    printf("����������Ч���ȣ�>");
    scanf("%d", &numsSize);    //����������Ч����

    int nums[1000] = { 0 };
    printf("����%d������ֵ��>", numsSize);
    for (i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);    //��������ֵ
    }

    int target = 0;
    printf("��������Ŀ��ֵ��>");
    scanf("%d", &target);    //����Ŀ��ֵ

    int a = 0;
    int* ret = twoSum(nums, numsSize, target, &a);    //�����Զ��庯��

    printf("[%d,%d]", *ret, a);    //��ӡ����±�

    return 0;
}