#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct List
{
    int num;
    struct List* next;
    struct List* find;
};

struct List* rear = NULL;

struct List* InitList()
{
    struct List* head = (struct List*)malloc(sizeof(struct List));
    assert(head);
    head->num = 0;
    head->next = head->find = NULL;
    rear = head;
    return head;
}

struct List* CreateNode(int num)
{
    struct List* newNode = (struct List*)malloc(sizeof(struct List));
    assert(newNode);
    newNode->num = num;
    newNode->next = newNode->find = NULL;
    return newNode;
}

void InsertNode(struct List* head, int num)
{
    struct List* newNode = CreateNode(num);
    rear->next = newNode;
    newNode->find = rear;
    rear = newNode;
}

void printList(struct List* head, int n)
{
    int i = 0;
    struct List* p;
    printf("*****************************************\n");
    printf("*******  0.正序输出    1.倒序输出  ******\n");
    printf("*****************************************\n");

    scanf("%d", &i);
    if (i == 0)
    {
        p = head->next;
        for (; i < n; i++)
        {
            printf("%d\t", p->num);
            p = p->next;
        }
    }
    else if (i == 1)
    {
        p = rear;
        for (; i <= n; i++)
        {
            printf("%d\t", p->num);
            p = p->find;
        }

    }
    else
    {
        printf("你输入的数据不合法，请重新开始:>\n");
        printList(head, n);
    }
    printf("\n\n");
    }

    int main()
    {
        struct List* list = InitList();
        for (int i = 0; i < 10; i++)
        {
            InsertNode(list, i);
        }
        printList(list, 10);

        return 0;
    }