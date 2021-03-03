#include <stdio.h>


//����ָ��
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;    //slowָ��������һ��
        fast = fast->next->next;    //fastָ������������
    }

    return slow;
}

int main()
{

	return 0;
}