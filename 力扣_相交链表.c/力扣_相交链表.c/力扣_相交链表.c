#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB){
    //��������������ֻҪ��һ��Ϊ�գ���ֱ�ӷ���NULL
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    int longA = 1;
    int longB = 1;
    while (curA->next)
    {
        longA++;
        curA = curA->next;
    }
    while (curB->next)
    {
        longB++;
        curB = curB->next;
    }

    //��ʱ��ָ��ָ������β��������β����ȼ���ʾ���ཻ��ֱ�ӷ���NULL
    if (curA != curB)
        return NULL;

    //ʹ��ָ���ٴ�ָ���������ͷԪ�أ��ٱȽ��������ȣ�ʹ�����������߲��첽
    curA = headA;
    curB = headB;
    int i = 0;
    if (longA > longB)
    {
        i = longA - longB;
        while (i--)
            curA = curA->next;
    }
    else if (longA < longB)
    {
        i = longB - longA;
        while (i--)
            curB = curB->next;
    }

    //��ͷ��ʼ�Ƚ�ֱ���ڵ������������
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}

int main()
{

    return 0;
}