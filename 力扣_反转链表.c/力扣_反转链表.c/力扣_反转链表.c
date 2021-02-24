#include <stdio.h>

struct ListNode 
{
    int val;
    struct ListNode* next;
};


//方法一
struct ListNode* reverseList1(struct ListNode* head) {
    //判断链表是否只有1个元素或无元素
    if (head == NULL || head->next == NULL)
        return head;

    //定义三个结构体指针分别指向NULL，head和head的下一个
    struct ListNode* n1, * n2, * n3;
    n1 = NULL;
    n2 = head;
    n3 = head->next;

    //若n2为真则继续迭代
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}
//方法二
struct ListNode* reverseList2(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* cur, * next, * newhead;
    newhead = NULL;
    cur = head;
    next = head->next;

    while (cur != NULL)
    {
        cur->next = newhead;
        newhead = cur;
        cur = next;
        if (next)
            next = next->next;
    }

    return newhead;
}

int main()
{


    return 0;
}