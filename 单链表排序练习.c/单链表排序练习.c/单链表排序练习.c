#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode* next;    
};

//创建表头
struct ListNode* createList()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(head);
    head->next = NULL;
    head->val = 0;

    return head;
}

//创建节点
struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(newNode);

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

//插入
void InsertNodeByList(struct ListNode* head, int val)
{
    struct ListNode* newNode = createNode(val);

    if (head->next != NULL)
    {
        newNode->next = head->next;
    }
    else
    {
        newNode->next = NULL;
    }

    head->next = newNode;
}

//排序(低->高)有bug
struct ListNode* sortInList(struct ListNode* head) 
{
    int v = 0;
    struct ListNode* newNode = head->next;
    struct ListNode* newNodeBehind = newNode->next;
    assert(newNode && newNodeBehind);

    int i = 0;
    while (newNode != NULL)
    {
        newNode = newNode->next;
        i++;
    }
    newNode = head->next;
    //struct ListNode* n = newNode;
    //struct ListNode* m = newNodeBehind;
    do
    {
        //n = newNode->next;
        //m = newNodeBehind->next;
        while (newNode->next)
        {
            if (newNode->val > newNodeBehind->val)
            {
                v = newNodeBehind->val;
                newNodeBehind->val = newNode->val;
                newNode->val = v;
            }
            newNode = newNodeBehind;
            if (newNode->next != NULL)
            {
                newNodeBehind = newNodeBehind->next;
            }
        }
        newNode = head->next;
        newNodeBehind = newNode->next;
        i--;
    } while (i > 0 );
    
    return head;
    // write code here
}

//输出链表
void printfList(struct ListNode* Node)
{
    Node = Node->next;
    while (Node)
    {
        printf("%d\t", Node->val);
        Node = Node->next;
    }
    printf("\n");
}


void main()
{
    struct ListNode* head = createList();

    InsertNodeByList(head, 5);
    InsertNodeByList(head, -4);
    InsertNodeByList(head, 2);
    InsertNodeByList(head, -3);
    InsertNodeByList(head, 1);

    printfList(head);

    head = sortInList(head);

    printfList(head);
}





