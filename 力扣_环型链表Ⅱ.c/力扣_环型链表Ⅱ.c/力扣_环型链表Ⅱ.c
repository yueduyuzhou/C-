#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;
        //slow和fast相遇时，使slow指向原表头，与fast同时一步一步走
        if (slow == fast)
        {
            slow = head;
            //走到相等时跳出循环，返回此时fast或slow指向的节点
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    //若跳出循环，表示此链表无环，返回NULL
    return NULL;
}

int main()
{
	return 0;
}