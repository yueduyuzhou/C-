#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode* next;    
};

//����ͷ�ڵ�
struct ListNode* listNode()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(head);
    
    head->next = NULL;
    head->val = 1;

    return head;
}

//�����½ڵ�
struct ListNode* createNewNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(newNode);

    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

//����ڵ�
struct ListNode* insertNode(struct ListNode* head,int val)
{
    struct ListNode* newNode = createNewNode(val);
    
    newNode->next = head->next;
    head->next = newNode;

    return head;
}

//ɾ���ڵ�
struct ListNode* deleteNode(struct ListNode* head, int val) 
{
    struct ListNode* newNode = head->next;
    struct ListNode* newNodeFront = head;

    assert(head->next);

    while (newNode != NULL)
    {
        if (newNode->val == val)
        {
            newNodeFront->next = newNode->next;
            return head;
        }
        newNodeFront = newNode;
        newNode = newNode->next;
    }
    return head;
}

//��ӡ����
void printList(struct ListNode* head)
{
    struct ListNode* newNode = head->next;

    while (newNode != NULL)
    {
        printf("%d\t", newNode->val);
        newNode = newNode->next;
    }
    printf("\n\n\n");
}

int main()
{
    struct ListNode* list = listNode();
    insertNode(list, -99);
    insertNode(list, -3);
    insertNode(list, -5);
    insertNode(list, -3);
    printList(list);

    deleteNode(list, -3);
    printList(list);
    
	return 0;
}