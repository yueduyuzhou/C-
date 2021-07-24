#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* n1, * n2, * n3;
    n1 = NULL;
    n2 = head;
    n3 = head->next;

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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* leftp = head;
    struct ListNode* rightp = head;
    struct ListNode* leftprev = NULL;

    int n = left;

    while (--left) { if (left == 1) { leftprev = leftp; }; leftp = leftp->next; }
    while (--right) { rightp = rightp->next; }

    struct ListNode* tmp = rightp->next;
    rightp->next = NULL;
    rightp = reverseList(leftp);

    leftp->next = tmp;
    if (n > 1) { leftprev->next = rightp; }
    if (n == 1) { head = rightp; }

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
    reverseBetween(head, 2, 4);
	return 0;
}