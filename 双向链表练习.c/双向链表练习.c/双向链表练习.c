#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct DoubleList_people
{
	//char name[Max_name_size];
	int age;
	//int tele[Max_tele_size];
	struct DoubleList_people* prev;
	struct DoubleList_people* next;
};

int size = 0;

//��������
struct DoubleList_people* CreateList()
{
	struct DoubleList_people* head = (struct DoubleList_people*)malloc(sizeof(struct DoubleList_people));
	assert(head);

	head->prev = NULL;
	head->next = NULL;

	return head;
}

//�����ڵ�
struct DoubleList_people* CreateNode(/*char* name,*/ int age/*, int* tele*/)
{
	struct DoubleList_people* newNode = (struct DoubleList_people*)malloc(sizeof(struct DoubleList_people));
	assert(newNode);

	newNode->prev = NULL;
	newNode->next = NULL;
	//newNode->name = *name;
	newNode->age = age;
	//newNode->tele = *tele;

	return newNode;
}

//����ָ���ڵ�
void InsertToList(struct DoubleList_people* head,/* int* name,*/ int age/*, int* tele*/, int to)
{
	struct DoubleList_people* newNode = CreateNode(/*name,*/ age/*, tele*/);

	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->prev = head;
		size++;
		return;
	}
	else if (to > size)
	{
		struct DoubleList_people* ptmp = head;
		while (ptmp->next != NULL)
		{
			ptmp = ptmp->next;
		}
		ptmp->next = newNode;
		newNode->prev = ptmp;
		newNode->next = NULL;
		size++;
		return;
	}

	if (to >= 0 && to <= size)
	{
		struct DoubleList_people* ptmp = head->next;
		for (int i = 1; i < to; i++)
		{
			ptmp = ptmp->next;
		}
		newNode->prev = ptmp->prev;
		newNode->next = ptmp;
		ptmp->prev->next = newNode;
		ptmp->prev = newNode;
		size++;
		return;
	}
}

void PrintList(struct DoubleList_people* head)
{
	struct DoubleList_people* pNode = head->next;
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", pNode->age);
		pNode = pNode->next;
	}
	printf("\n\n");
}

//ɾ���ڵ�
void DeleteToNode(struct DoubleList_people* head, int to)
{
	struct DoubleList_people* deNode = head->next;
	if (head->next == NULL)
	{
		printf("������Ϊ��");
		return;
	}
	else if (to == size)
	{
		while (deNode->next != NULL)
			deNode = deNode->next;
		deNode->prev->next = NULL;
		free(deNode);
		size--;
		return;
	}
	else if (to > 0 && to < size)
	{
		for (int i = 1; i < to; i++)
		{
			deNode = deNode->next;
		}
		deNode->prev->next = deNode->next;
		deNode->next->prev = deNode->prev;
		free(deNode);
		size--;
		return;
	}
	else
		printf("����Υ����\n");
}

//����
int ShowToNode(struct DoubleList_people* head, int to)
{
	struct DoubleList_people* tNode = head->next;
	for (int i = 1; i < to; i++)
	{
		tNode = tNode->next;
	}
	return tNode->age;
}

//�Ľڵ�����
void ChangeToNode(struct DoubleList_people* head, int to, int num)
{
	struct DoubleList_people* chNode = head->next;
	for (int i = 1; i < to; i++)
	{
		chNode = chNode->next;
	}
	chNode->age = num;
}

int main()
{
	struct DoubleList_people* List = CreateList();
	InsertToList(List, 10, 1);
	InsertToList(List, 11, 2);
	InsertToList(List, 13, 3);
	InsertToList(List, 14, 4);
	PrintList(List);
	InsertToList(List, 12, 3);    //���ڵ������ڵ��λ��
	//InsertToList(List, 16, 6);    //���ڵ������ڵ��λ��
	InsertToList(List, 15, 6);    //���ڵ������ڵ��λ��
	PrintList(List);

	DeleteToNode(List, 5);    //ɾ��������ڵ�
	PrintList(List);

	printf("%d\n\n", ShowToNode(List, 5));    //���ҵ�����ڵ�����

	ChangeToNode(List, 1, 25);    //��List����ĵ�һ���ڵ����ݸ�Ϊ25
	ChangeToNode(List, 4, 33);	  //��List����ĵ��ĸ��ڵ����ݸ�Ϊ33
	PrintList(List);

	return 0;
}







