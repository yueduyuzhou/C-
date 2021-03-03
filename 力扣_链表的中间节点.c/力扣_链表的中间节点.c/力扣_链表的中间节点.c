#include <stdio.h>


//快慢指针
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;    //slow指针依次走一步
        fast = fast->next->next;    //fast指针依次走两步
    }

    return slow;
}

int main()
{

	return 0;
}