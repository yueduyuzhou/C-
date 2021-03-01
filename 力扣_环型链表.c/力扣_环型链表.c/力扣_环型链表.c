#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    //�����޻�ʱ���ڵ���ż������fastָ���ʱ����
    //�ڵ�����������fast->nextָ���ʱ����
    while (fast && fast->next)
    {
        //slowһ����һ��
        //fastһ��������
        slow = slow->next;
        fast = fast->next->next;
        //�������л�ʱ��ָ���һֱ�ߣ�ֱ��fast׷��slow������true
        if (slow == fast)
            return true;
    }
    //�������ѭ������ʾ�����޻�������false
    return false;
}

int main()
{
	return 0;
}