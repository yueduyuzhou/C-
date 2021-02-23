struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ��ֱ�ӷ���ͷ
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* sorthead = head;
    struct ListNode* cur = head->next;
    sorthead->next = NULL;

    while (cur)
    {
        struct ListNode* next = cur->next;
        //��cur���뵽sorthead�У�����������
        if (cur->val <= sorthead->val)
        {
            //ͷ��
            cur->next = sorthead;
            sorthead = cur;
        }
        else
        {
            //�м��β��
            struct ListNode* sortprev = sorthead;
            struct ListNode* sortcur = sortprev->next;
            while (sortcur)
            {
                //cur->valС��sort->val���м���룬����sortcur��sortprev�����һ��
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
            //�����û���м�������������β��
            if (sortcur == NULL)
            {
                sortprev->next = cur;
                cur->next = NULL;
            }
        }
        //����
        cur = next;
    }
    return sorthead;
}

int main()
{
    return 0;
}