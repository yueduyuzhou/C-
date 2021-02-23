struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    //链表为空或只有一个元素时，直接返回头
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* sorthead = head;
    struct ListNode* cur = head->next;
    sorthead->next = NULL;

    while (cur)
    {
        struct ListNode* next = cur->next;
        //把cur插入到sorthead中，并保持有序
        if (cur->val <= sorthead->val)
        {
            //头插
            cur->next = sorthead;
            sorthead = cur;
        }
        else
        {
            //中间或尾插
            struct ListNode* sortprev = sorthead;
            struct ListNode* sortcur = sortprev->next;
            while (sortcur)
            {
                //cur->val小于sort->val，中间插入，否则sortcur和sortprev向后走一步
                if (cur->val <= sortcur->val)
                {
                    cur->next = sortcur;
                    sortprev->next = cur;
                    break;
                }
                else
                {
                    sortprev = sortcur;
                    sortcur = sortcur->next;
                }
            }
            //如果是没有中间插入就跳出，则尾插
            if (sortcur == NULL)
            {
                sortprev->next = cur;
                cur->next = NULL;
            }
        }
        //迭代
        cur = next;
    }
    return sorthead;
}

int main()
{
    return 0;
}