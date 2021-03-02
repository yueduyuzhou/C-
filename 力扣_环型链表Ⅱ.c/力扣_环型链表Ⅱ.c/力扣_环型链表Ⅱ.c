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
        //slow��fast����ʱ��ʹslowָ��ԭ��ͷ����fastͬʱһ��һ����
        if (slow == fast)
        {
            slow = head;
            //�ߵ����ʱ����ѭ�������ش�ʱfast��slowָ��Ľڵ�
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    //������ѭ������ʾ�������޻�������NULL
    return NULL;
}

int main()
{
	return 0;
}