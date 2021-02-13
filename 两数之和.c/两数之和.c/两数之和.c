#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int n = 0, m = 0;
    for (n = 0; n < numsSize; n++)    //从第0个开始比较
    {
        for (m = n + 1; m < numsSize; m++)    //从第n + 1个开始与第n个开始比较
        {
            if (nums[n] + nums[m] == target)    //判断
            {
                *returnSize = n;    //改变主函数的值，传出一个下标的地址
                return &m;    //返回另一个下标
            }
        }
    }
}

int main()
{
    int numsSize = 0,i = 0;
    printf("输入数组有效长度：>");
    scanf("%d", &numsSize);    //输入数组有效长度

    int nums[1000] = { 0 };
    printf("输入%d个数组值：>", numsSize);
    for (i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);    //输入数组值
    }

    int target = 0;
    printf("输入整数目标值：>");
    scanf("%d", &target);    //输入目标值

    int a = 0;
    int* ret = twoSum(nums, numsSize, target, &a);    //调用自定义函数

    printf("[%d,%d]", *ret, a);    //打印结果下标

    return 0;
}