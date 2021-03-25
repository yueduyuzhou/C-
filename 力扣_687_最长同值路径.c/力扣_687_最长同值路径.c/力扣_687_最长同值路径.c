#include <stdio.h>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
 //int tmp = 0;
 //int length = 0;

int Max(int const a, int const b)
{
    return a > b ? a : b;
}

//int longestPath (struct TreeNode* root, struct TreeNode* rootpar, int* tmp, int* length){
        //递归
//    if (root->left != NULL){
//        longestPath(root->left, root, tmp, length);
//    }
//    if (root->right != NULL){
//        longestPath(root->right, root, tmp, length);
//    }

//    if (rootpar != NULL && root->val == rootpar->val)
//    {
//        *tmp = Max (*tmp, *length);
//        if (rootpar->left->val == rootpar->val)
//        {
//            return ++(*tmp);
//        }
//        else
//        {
//            return ++(*length);        
//        }

//    }
//    else
//    {
//        *tmp = Max (*tmp, *length);
//        *length = 0;
//        return *tmp;
//    }
//}

//int longestUnivaluePath(struct TreeNode* root){
//    if (root == NULL || (root->left == NULL && root->right == NULL))
//    {
//        return 0;
//    }

//    int tmp = 0,length = 0;
//    return longestPath (root, NULL, &tmp, &length);
//}

/*------------------------------------------------------------------------------------------*/

//int res = 0;    //避免使用全局变量

//搜寻以p为起点的最长同值路径：要么是以p为起点的左子树；要么是以p为起点的右子树
int getlongest(struct TreeNode* p, int* res)
{
    //终止条件
    if (p == NULL)  return 0;

    //p的左、右子树的最长同值路径
    int left = getlongest(p->left, res);
    int righ = getlongest(p->right, res);

    //节点值等于节点左子树的值，最长同值路径要加上左子树的最长同值路径，不等，左子树的路径为0
    left = (p->left != NULL && p->val == p->left->val) ? left + 1 : 0;
    righ = (p->right != NULL && p->val == p->right->val) ? righ + 1 : 0;

    *res = Max(*res, left + righ);
    return Max(left, righ);
}

int longestUnivaluePath(struct TreeNode* root)
{
    int res = 0;
    getlongest(root, &res);
    return res;
}

int main()
{
	return 0;
}