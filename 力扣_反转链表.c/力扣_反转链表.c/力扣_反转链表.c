#include <stdio.h>

struct ListNode 
{
    int val;
    struct ListNode* next;
};


//����һ
struct ListNode* reverseList1(struct ListNode* head) {
    //�ж������Ƿ�ֻ��1��Ԫ�ػ���Ԫ��
    if (head == NULL || head->next == NULL)
        return head;

    //���������ṹ��ָ��ֱ�ָ��NULL��head��head����һ��
    struct ListNode* n1, * n2, * n3;
    n1 = NULL;
    n2 = head;
    n3 = head->next;

    //��n2Ϊ�����������
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
//������
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