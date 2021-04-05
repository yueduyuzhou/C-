#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

#define MaxSize 10000

//反转结果和链表
void Reverse(int** res, int** resColumnSizes, int resSize)
{
    int left = 0;
    int right = resSize - 1;

    while (left < right)
    {
        int* tmp1 = res[left];
        res[left] = res[right];
        res[right] = tmp1;
        int tmp2 = resColumnSizes[0][left];
        resColumnSizes[0][left] = resColumnSizes[0][right];
        resColumnSizes[0][right] = tmp2;
        left++, right--;
    }
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    //初始化*returnSize
    *returnSize = 0;

    if (root == NULL) { return NULL; }

    //定义需要的量并分配空间
    int** res = (int**)malloc(sizeof(int*) * MaxSize);
    assert(res);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MaxSize);
    assert(*returnColumnSizes);
    //定义队列
    struct TreeNode* MyQueue[MaxSize];

    int mq = 0, mqtmp = 0, tmp = 0, k = 0;
    MyQueue[mq++] = root;

    while (tmp != mq)
    {
        //保存mq的值，因为后面的操作会改变mq
        mqtmp = mq;
        k = 0;
        //开辟结果二维数组res的每一个元素数组
        res[*returnSize] = (int*)malloc(sizeof(int) * (mqtmp - tmp));
        assert(res[*returnSize]);
        while (tmp < mqtmp)
        {
            //出队
            struct TreeNode* p = MyQueue[tmp++];
            //把出队的节点值数据放入res
            res[*returnSize][k++] = p->val;

            //节点左右孩子为真时分别入队
            if (p->left) { MyQueue[mq++] = p->left; }
            if (p->right) { MyQueue[mq++] = p->right; }
        }
        //把结果每一个元素数组长度放入returnColumnSizes
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
    }
    //反转
    Reverse(res, returnColumnSizes, *returnSize);

    return res;
}

int main()
{
	return 0;
}