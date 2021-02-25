#include <malloc.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //cur为真，动态开辟一个空间拷贝cur的值，然后在cur后插入
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->random = NULL;
        copy->next = cur->next;
        cur->next = copy;

        //迭代
        cur = copy->next;
    }

    cur = head;
    //cur为真，当cur->random为真时，使cur的拷贝节点的random指向cur->random的拷贝
    while (cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        else
            cur->next->random = NULL;

        //迭代
        cur = cur->next->next;
    }

    struct Node* copy = head;
    struct Node* prev = head;
    //head为真，使copy指向第一个拷贝节点
    if (head)
    {
        copy = head->next;
        //head->next为真，使prev与cur都指向第二个原节点
        if (head->next)
            prev = cur = copy->next;
    }
    //cur为真，
    //copy从第一个拷贝节点开始，copy->next指向下一个拷贝节点，后copy指向下一个拷贝节点
    //cur从第二个原节点开始，cur->next指向下一个原节点，后copy指向下一个原节点
    while (cur)
    {
        copy->next = cur->next;
        copy = cur->next;
        cur->next = copy->next;
        cur = copy->next;
    }
    //head为真，此时第一个原节点还指向第一个拷贝节点，使copy指向第一个拷贝节点，再使第一个原节点->next指向下一个原节点
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