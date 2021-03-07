#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB){
    //传进来的两链表只要有一个为空，则直接返回NULL
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    int longA = 1;
    int longB = 1;
    while (curA->next)
    {
        longA++;
        curA = curA->next;
    }
    while (curB->next)
    {
        longB++;
        curB = curB->next;
    }

    //此时两指针指向链表尾，若链表尾不相等即表示无相交，直接返回NULL
    if (curA != curB)
        return NULL;

    //使两指针再次指向两链表的头元素，再比较两链表长度，使长的链表先走差异步
    curA = headA;
    curB = headB;
    int i = 0;
    if (longA > longB)
    {
        i = longA - longB;
        while (i--)
            curA = curA->next;
    }
    else if (longA < longB)
    {
        i = longB - longA;
        while (i--)
            curB = curB->next;
    }

    //从头开始比较直到节点相等跳出返回
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}

int main()
{

    return 0;
}