//³¬Ê±

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createnode(int val)
{
    struct ListNode* newnode = malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;

    return newnode;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && l2) { return l2; }
    if (l1 && !l2) { return l1; }
    if (!l1 && !l2) { return NULL; }

    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;
    struct ListNode* newhead = NULL;
    struct ListNode* t = NULL;

    if (tmp1 && tmp2 && tmp1->val < tmp2->val)
    {
        newhead = createnode(tmp1->val);
        tmp1 = tmp1->next;
    }
    else
    {
        newhead = createnode(tmp2->val);
        tmp2 = tmp2->next;
    }
    t = newhead;

    while (tmp1 && tmp2)
    {
        if (tmp1 && tmp2 && tmp1->val <= tmp2->val)
        {
            t->next = createnode(tmp1->val);
            t = t->next;
            tmp1 = tmp1->next;
        }
        else
        {
            t->next = createnode(tmp2->val);
            t = t->next;
            tmp2 = tmp2->next;
        }
    }

    if (tmp1)
    {
        t->next = tmp1;
    }
    else if (tmp2)
    {
        t->next = tmp2;
    }

    return newhead;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize <= 0) { return NULL; }
    if (listsSize == 1) { return lists[0]; }

    struct ListNode* res = mergeTwoLists(lists[0], lists[1]);

    int i = 2;
    while (i < listsSize)
    {
        res = mergeTwoLists(res, lists[i++]);
    }

    return res;
}


/**************************************************************************************/

struct ListNode* createnode(int val)
{
    struct ListNode* newnode = malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;

    return newnode;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && l2) { return l2; }
    if (l1 && !l2) { return l1; }
    if (!l1 && !l2) { return NULL; }

    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;
    struct ListNode* newhead = NULL;
    struct ListNode* t = NULL;

    if (tmp1 && tmp2 && tmp1->val < tmp2->val)
    {
        newhead = createnode(tmp1->val);
        tmp1 = tmp1->next;
    }
    else
    {
        newhead = createnode(tmp2->val);
        tmp2 = tmp2->next;
    }
    t = newhead;

    while (tmp1 && tmp2)
    {
        if (tmp1 && tmp2 && tmp1->val <= tmp2->val)
        {
            t->next = createnode(tmp1->val);
            t = t->next;
            tmp1 = tmp1->next;
        }
        else
        {
            t->next = createnode(tmp2->val);
            t = t->next;
            tmp2 = tmp2->next;
        }
    }

    if (tmp1)
    {
        t->next = tmp1;
    }
    else if (tmp2)
    {
        t->next = tmp2;
    }

    return newhead;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize <= 0) { return NULL; }
    if (listsSize == 1) { return lists[0]; }

    lists[0] = mergeTwoLists(lists[0], lists[1]);
    lists[1] = NULL;

    int i = 2, j = 1;
    int s = listsSize;
    while (s != 1)
    {
        while (i < s && i + 1 < s)
        {
            lists[j] = mergeTwoLists(lists[i], lists[i + 1]);
            lists[i + 1] == NULL;
            i += 2;
            j++;
        }
        if (s % 2 != 0)
        {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
            lists[i] = NULL;
        }
        s = j;
        i = 0;
        j = 0;
    }

    return lists[0];
}