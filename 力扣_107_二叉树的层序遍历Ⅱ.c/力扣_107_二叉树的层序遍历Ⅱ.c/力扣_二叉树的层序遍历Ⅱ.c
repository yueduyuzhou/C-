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

//��ת���������
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
    //��ʼ��*returnSize
    *returnSize = 0;

    if (root == NULL) { return NULL; }

    //������Ҫ����������ռ�
    int** res = (int**)malloc(sizeof(int*) * MaxSize);
    assert(res);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MaxSize);
    assert(*returnColumnSizes);
    //�������
    struct TreeNode* MyQueue[MaxSize];

    int mq = 0, mqtmp = 0, tmp = 0, k = 0;
    MyQueue[mq++] = root;

    while (tmp != mq)
    {
        //����mq��ֵ����Ϊ����Ĳ�����ı�mq
        mqtmp = mq;
        k = 0;
        //���ٽ����ά����res��ÿһ��Ԫ������
        res[*returnSize] = (int*)malloc(sizeof(int) * (mqtmp - tmp));
        assert(res[*returnSize]);
        while (tmp < mqtmp)
        {
            //����
            struct TreeNode* p = MyQueue[tmp++];
            //�ѳ��ӵĽڵ�ֵ���ݷ���res
            res[*returnSize][k++] = p->val;

            //�ڵ����Һ���Ϊ��ʱ�ֱ����
            if (p->left) { MyQueue[mq++] = p->left; }
            if (p->right) { MyQueue[mq++] = p->right; }
        }
        //�ѽ��ÿһ��Ԫ�����鳤�ȷ���returnColumnSizes
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
    }
    //��ת
    Reverse(res, returnColumnSizes, *returnSize);

    return res;
}

int main()
{
	return 0;
}