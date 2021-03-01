#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    //链表无环时，节点是偶数个，fast指向空时跳出
    //节点是奇数个，fast->next指向空时跳出
    while (fast && fast->next)
    {
        //slow一次走一步
        //fast一次走两步
        slow = slow->next;
        fast = fast->next->next;
        //当链表有环时两指针会一直走，直到fast追上slow，返回true
        if (slow == fast)
            return true;
    }
    //如果跳出循环，表示链表无环，返回false
    return false;
}

int main()
{
	return 0;
}