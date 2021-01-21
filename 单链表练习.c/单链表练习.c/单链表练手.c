#include <stdio.h>
#include <stdlib.h>
#include <assert.h>        //指定节点插入有bug

//定义结构体
struct List_girl
{
	int no;
	struct List_girl* next;
};

struct List_girl* CreateTail()
{
	struct List_girl* tail = (struct List_girl*)malloc(sizeof(struct List_girl));
	assert(tail);

	tail->next = NULL;
	tail->no = -1;

	return tail;
}

struct List_girl* CreateList()
{
	struct List_girl* head = (struct List_girl*)malloc(sizeof(struct List_girl));
	assert(head);

	head->next = NULL;
	head->no = 0;

	return head;
}

struct List_girl* CreateNode(int no)
{
	struct List_girl* newNode = (struct List_girl*)malloc(sizeof(struct List_girl));
	assert(newNode);
	
	newNode->next = NULL;
	newNode->no = no;

	return newNode;
}

//头插
//void InsertList(struct List_girl* head, int no)
//{
//	struct List_girl* newNode = CreateNode(no);
//	assert(head && newNode);
//
//	newNode->next = head->next;
//	head->next = newNode;
//
//}

//按编号插入(插入排序)
struct List_girl* InsertToList(struct List_girl* head,struct List_girl* tail, int no)
{
	struct List_girl* Node = head->next;
	struct List_girl* NodeFront = head;
	struct List_girl* newNode = CreateNode(no);
	//当链表为空或新节点编号小于等于第一个节点编号时，插到头指针后
	if (head->next == NULL || newNode->no <= Node->no)
	{
		tail = head->next = newNode;
		newNode->next = NULL;
		return tail;
	}
	//当新节点编号大于等于尾指针的编号，插到链表尾部
	else if (newNode->no >= tail->no)
	{
		tail->next = newNode;
		newNode->next = NULL;
		tail = newNode;
		return tail;
	}
	//新节点编号在链表中间
	//assert(Node);
	while (1)
	{
		if (Node != 0)
		{
			if (newNode->no <= Node->no && newNode->no >= NodeFront->no)
			{
				newNode->next = NodeFront->next;
				NodeFront->next = newNode;
				break;
			}
			Node = Node->next;
			NodeFront = Node->next;
		}
	}
	return tail;
}

//删除指定节点
void DeleteNode(struct List_girl* head, struct List_girl* tail, int no)
{
	struct List_girl* deNodeFront = head;
	struct List_girl* deNode = head->next;
	//assert()
	while (deNode->no != no)
	{
		deNodeFront = deNodeFront->next;
		deNode = deNode->next;
	}
	if (deNode->next == NULL)
	{
		deNodeFront->next = deNode->next;
		tail->next = deNodeFront;
		free(deNode);	
	}
	else
	{
		deNodeFront->next = deNode->next;
		free(deNode);
	}
}

//查找指定节点
struct List_girl* ShowNode(const struct List_girl* head,int no)
{
	assert(head->next);
	struct List_girl* prNode = head->next;
	while (prNode->no != no)
	{
		prNode = prNode->next;
	}
	return prNode;
}

//更改指定节点
void ChangeNode(struct List_girl* head, int no,int noo)
{
	struct List_girl* chNode = ShowNode(head, no);
	chNode->no = noo;
}

//打印链表
void printList(struct List_girl* head)
{
	struct List_girl* pMove = head->next;
	while (pMove != NULL)
	{
		printf("%d\t", pMove->no);
		pMove = pMove->next;
	}
	printf("\n\n");
}

int main()
{
	struct List_girl* list = CreateList();
	struct List_girl* tail = CreateTail();
	tail = InsertToList(list, tail, 1);
	tail = InsertToList(list, tail, 3);
	tail = InsertToList(list, tail, 4);
	tail = InsertToList(list, tail, 6);
	//InsertList(list, 1);
	//InsertList(list, 3);
	//InsertList(list, 4);
	//InsertList(list, 6);
	printf("原来的链表:>");
	printList(list);

	tail = InsertToList(list, tail, 5);
	tail = InsertToList(list, tail, 2);
	//InsertList(list, 5);
	//InsertList(list, 2);
	printf("插入后的链表:>");
	printList(list);

	DeleteNode(list, tail, 4);
	printf("删除后的链表:>");
	printList(list);

	ChangeNode(list, 5, 4);
	ChangeNode(list, 6, 5);
	printf("更改后的链表:>");
	printList(list);
	return 0;
}
