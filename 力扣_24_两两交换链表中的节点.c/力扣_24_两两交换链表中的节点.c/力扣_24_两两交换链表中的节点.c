#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};
 


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }

    struct ListNode* tmp = head;
    struct ListNode* cur = head->next;

    tmp->next = cur->next;
    cur->next = tmp;
    head = cur;

    while (tmp->next != NULL && tmp->next->next != NULL)
    {
        cur = tmp;
        tmp = tmp->next;
        cur->next = tmp->next;

        cur = tmp;
        tmp = tmp->next;
        cur->next = tmp->next;

        tmp->next = cur;
        cur = tmp;
        tmp = tmp->next;
    }

    return head;
}

int main()
{
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode* a = malloc(sizeof(struct ListNode));
    a->val = 2;
    struct ListNode* b = malloc(sizeof(struct ListNode));
    b->val = 3;
    struct ListNode* c = malloc(sizeof(struct ListNode));
    c->val = 4;
    struct ListNode* d = malloc(sizeof(struct ListNode));
    d->val = 5;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    swapPairs(head);

	return 0;
}