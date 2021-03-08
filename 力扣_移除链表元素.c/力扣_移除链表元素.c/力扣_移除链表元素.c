#include <stdio.h>

//struct ListNode* removeElements(struct ListNode* head, int val){
//    if (head == NULL || head->next == NULL)
//        return head;
//    while (head->val == val)
//    {
//        head = head->next;
//        if (head == NULL || head->next == NULL)
//            return head;
//    }
//
//    struct ListNode* cur = head->next;
//    struct ListNode* prve = head;
//
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            prve->next = cur->next;
//            cur = cur->next;
//        }
//        else
//        {
//            prve = prve->next;
//            cur = cur->next;
//        }
//    }
//
//    return head;
//}

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return head;
    while (head->val == val)
    {
        head = head->next;
        if (head == NULL)
            return head;
    }

    struct ListNode* cur = head->next;
    struct ListNode* prve = head;

    while (cur)
    {
        if (cur->val == val)
        {
            prve->next = cur->next;
            cur = cur->next;
        }
        else
        {
            prve = prve->next;
            cur = cur->next;
        }
    }

    return head;
}

int main()
{
	return 0;
}