#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* CreatNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(newNode);
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = 1, len2 = 1, len = 0;
    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;
    //计算两链表的长度
    while (tmp1->next || tmp2->next)
    {
        if (tmp1->next) { len1++; tmp1 = tmp1->next; }
        if (tmp2->next) { len2++; tmp2 = tmp2->next; }
    }
    //printf ("%d %d",len1,len2);
    //补齐短的链表
    if (len1 > len2)
    {
        len = len1 - len2;
        while (len--)
        {
            tmp2->next = CreatNode(0);
            tmp2 = tmp2->next;
        }
    }
    if (len2 > len1)
    {
        len = len2 - len1;
        while (len--)
        {
            tmp1->next = CreatNode(0);
            tmp1 = tmp1->next;
        }
    }
    len = Max(len1, len2);
    //printf("%d",len);

    int sum = 0;
    int sign = 0;
    tmp1 = l1;
    tmp2 = l2;
    while (len--)
    {
        sum = tmp1->val + tmp2->val + sign;
        if (sum > 9) { sign = 1; }
        else { sign = 0; }

        tmp1->val = sum % 10;

        if (tmp1->next && tmp2->next)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    //printf("%d", tmp1->val);
    if (sign == 1) { tmp1->next = CreatNode(1); }
    return l1;
}

int main()
{
    return 0;
}