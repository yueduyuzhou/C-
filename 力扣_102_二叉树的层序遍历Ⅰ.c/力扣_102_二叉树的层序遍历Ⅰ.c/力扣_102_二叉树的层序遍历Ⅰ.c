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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (root == NULL) { return NULL; }

    int** res = (int**)malloc(sizeof(int*) * MaxSize);
    assert(res);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MaxSize);
    assert(*returnColumnSizes);
    struct TreeNode* MyQueue[MaxSize];

    int mq = 0, mqtmp = 0, tmp = 0, k = 0;
    MyQueue[mq++] = root;

    while (tmp != mq)
    {
        mqtmp = mq;
        k = 0;
        res[*returnSize] = (int*)malloc(sizeof(int) * (mqtmp - tmp));
        assert(res[*returnSize]);
        while (tmp < mqtmp)
        {
            struct TreeNode* p = MyQueue[tmp++];
            res[*returnSize][k++] = p->val;

            if (p->left) { MyQueue[mq++] = p->left; }
            if (p->right) { MyQueue[mq++] = p->right; }
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
    }
    return res;
}

int main()
{
	return 0;
}