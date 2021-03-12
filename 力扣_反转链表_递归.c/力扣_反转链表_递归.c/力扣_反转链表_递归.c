#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    //返回条件
    if (head == NULL || head->next == NULL)
        return head;
    //接收返回值
    struct ListNode* cur = reverseList(head->next);
    //反转，返回反转后的结果
    head->next->next = head;
    head->next = NULL;
    return cur;
}

int main()
{
	return 0;
}