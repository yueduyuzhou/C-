#include <stdio.h>
#include <assert.h>
#include <malloc.h>

 static struct ListNode* rear = NULL;

struct ListNode
{
	int data;
	struct ListNode* next;
};

struct ListNode* CreateNode(int num)
{
	struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(Node);
	Node->data = num;
	Node->next = NULL;
	return Node;
}

struct ListNode* InitList()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(head);
	head->data = 0;
	head->next = NULL;
	return head;
}

//增
void InsertList(struct ListNode* head, int num)
{
	if (head->next == NULL)
	{
		struct ListNode* Node = CreateNode(num);
		head->next = Node;
		rear = Node;
	}
	else
	{
		struct ListNode* Node = CreateNode(num);
		rear->next = Node;
		rear = Node;
	}
}

//查
struct ListNode* FindNode(struct ListNode* head, int num)
{
	assert(head->next);
	struct ListNode* tmp = head->next;
	while (tmp->next->data != num)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			break;
	}
	return tmp;
}

//删
void DeleteNode(struct ListNode* head, int num)
{
	assert(head->next);
	struct ListNode* frdeNode = FindNode(head, num);
	//free(frdeNode->next);
	//frdeNode->next = NULL;
	frdeNode->next = frdeNode->next->next;
}

//改
void ChangeNode(struct ListNode* head, int num, int Tonum)
{
	struct ListNode* fichNode = FindNode(head, num);
	fichNode->next->data = Tonum;
}

//打印链表
void PrintList(struct ListNode* head)
{
	struct ListNode* prNode = head->next;
	while (prNode != NULL)
	{
		printf("%d\t", prNode->data);
		prNode = prNode->next;
	}
	printf("\n\n");
}

int main()
{
	struct ListNode* list = InitList();
	InsertList(list, 1);
	InsertList(list, 2);
	InsertList(list, 3);
	InsertList(list, 4);
	InsertList(list, 5);
	PrintList(list);

	DeleteNode(list, 3);
	PrintList(list);

	ChangeNode(list, 5, 99);
	PrintList(list);
	return 0;
}