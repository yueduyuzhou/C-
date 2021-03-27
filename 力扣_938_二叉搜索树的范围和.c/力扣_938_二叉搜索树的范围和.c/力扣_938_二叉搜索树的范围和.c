#include <stdio.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void getSum(struct TreeNode* root, int low, int high, int* sum)
{
    if (root->val >= low && root->val <= high) { sum += root->val; }

    if (root->left != NULL) { getSum(root->left, low, high, sum); }
    if (root->right != NULL) { getSum(root->right, low, high, sum); }

    //return *sum;
}

/*int getSum (struct TreeNode* root, int low, int high)
{
    if (root)
    {
        if (root->val < low) {return getSum (root->right, low, high);}
        else if (root->val > high) {return getSum (root->left, low, high);}
        else {return root->val + getSum (root->left, low, high) + getSum (root->right, low, high);}
    }

    return 0;
}*/

int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum = 0;

    //return getSum (root, low, high);
    getSum(root->right, low, high, &sum);

    //return sum;
}

int main()
{
	return 0;
}