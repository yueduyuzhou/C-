/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* gettail(struct ListNode* head)
{
    struct ListNode* tmp = head;
    while (tmp->next != NULL) { tmp = tmp->next; }
    return tmp;
}

int getlenth(struct ListNode* head)
{
    int count = 0;
    struct ListNode* tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) { return head; }

    struct ListNode* tail = gettail(head);
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    int len = getlenth(head);
    k %= len;

    while (k--)
    {
        if (fast->next == NULL) { fast = head; }
        else { fast = fast->next; }
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    tail->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}