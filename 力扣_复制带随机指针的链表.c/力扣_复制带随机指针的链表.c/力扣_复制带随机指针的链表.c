#include <malloc.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //curΪ�棬��̬����һ���ռ俽��cur��ֵ��Ȼ����cur�����
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->random = NULL;
        copy->next = cur->next;
        cur->next = copy;

        //����
        cur = copy->next;
    }

    cur = head;
    //curΪ�棬��cur->randomΪ��ʱ��ʹcur�Ŀ����ڵ��randomָ��cur->random�Ŀ���
    while (cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        else
            cur->next->random = NULL;

        //����
        cur = cur->next->next;
    }

    struct Node* copy = head;
    struct Node* prev = head;
    //headΪ�棬ʹcopyָ���һ�������ڵ�
    if (head)
    {
        copy = head->next;
        //head->nextΪ�棬ʹprev��cur��ָ��ڶ���ԭ�ڵ�
        if (head->next)
            prev = cur = copy->next;
    }
    //curΪ�棬
    //copy�ӵ�һ�������ڵ㿪ʼ��copy->nextָ����һ�������ڵ㣬��copyָ����һ�������ڵ�
    //cur�ӵڶ���ԭ�ڵ㿪ʼ��cur->nextָ����һ��ԭ�ڵ㣬��copyָ����һ��ԭ�ڵ�
    while (cur)
    {
        copy->next = cur->next;
        copy = cur->next;
        cur->next = copy->next;
        cur = copy->next;
    }
    //headΪ�棬��ʱ��һ��ԭ�ڵ㻹ָ���һ�������ڵ㣬ʹcopyָ���һ�������ڵ㣬��ʹ��һ��ԭ�ڵ�->nextָ����һ��ԭ�ڵ�
    if (head)
    {
        copy = head->next;
        head->next = prev;
    }

    return copy;
}

int amion()
{
    return 0;
}