#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //判断传进来的两个链表是否为空
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head;
    struct ListNode* tail;

    //先取两链表较小节点做为头head
    if (l1->val <= l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    tail = head;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    //出循环后有一个链表为空
    if (!l1)
        tail->next = l2;
    if (!l2)
        tail->next = l1;

    return head;
}

//代码改进
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head;
    struct ListNode* tail;

    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(newhead);
    tail = newhead;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (!l1)
        tail->next = l2;
    if (!l2)
        tail->next = l1;

    return newhead->next;
}

int main()
{


	return 0;
}