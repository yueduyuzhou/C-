#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    //��������
    if (head == NULL || head->next == NULL)
        return head;
    //���շ���ֵ
    struct ListNode* cur = reverseList(head->next);
    //��ת�����ط�ת��Ľ��
    head->next->next = head;
    head->next = NULL;
    return cur;
}

int main()
{
	return 0;
}