#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct student
{
	char name[20];
	int num;
	int math;
};

struct Node
{
	struct student data;
	struct Node* next;
};

////1.����ṹ��
//struct Node
//{
//	int data;
//	struct Node* next;
//};

//2.��������(ͷ)
struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));    //���ٿռ�
	assert(headNode);
	//headNode->data = 23;
	headNode->next = NULL;    //��ʱָ���

	return headNode;
}

//3.�����ڵ�
struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	assert(newNode);

	newNode->data = data;    //�����򸳳�ֵ
	newNode->next = NULL;    //��ʱָ���

	return newNode;
}

//4.��ӡ����
void printfList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("name\tnum\tmath\n");

	while (pMove)    //��ͷѰ��Ҫ��ӡ������
	{
		printf("%s\t%d\t%d\n", pMove->data.name, pMove->data.num, pMove->data.math);
		pMove = pMove->next;    //�����һλ
	}
	printf("\n\n");
}

//5.����ڵ�(ͷ�巨)
void InsertNodeByHead(struct Node* headNode, struct student data)
{
	struct Node* newNode = createNode(data);    //Ҫ���룬�ȴ����ڵ�

	newNode->next = headNode->next;    //ʹnewNode��ָ����ָ��ԭ��headNode����һ��
	headNode->next = newNode;    //ʹͷָ��Ҫ����Ľڵ�
}

//6.ɾ���ڵ�
int DeleteNodeByAppoinNum(struct Node* headNode, int num)
{
	struct Node* posNode = headNode->next;    //����һ��ָ��ָ����Ԫ��
	struct Node* posNodeFront = headNode;    //����һ��ָ��ָ��posNodeǰһ��ָ��

	if (posNode == NULL)    //��δ����ʱ���ж������Ƿ�Ϊ��
	{
		printf("������Ϊ��\n");
	}
	else
	{
		while (posNode->data.num != num)    //��������
		{
			posNodeFront = posNode;
			posNode = posNode->next;

			if (posNode == NULL)    //�Ҳ���Ҫɾ�������ݣ����������޴�����
			{
				printf("������û�и�����\n");
				return 0;    //����������
			}
		}
		posNodeFront->next = posNode->next;    //ʹposNodeFrontָ��ɾ��Ԫ�ص���һ��Ԫ��
		free(posNode);    //�黹ɾ��Ԫ�صĿռ�
	}
	return 0;
}

int main()
{
	struct Node* list = createList();    //����������������

	struct student stu;    //����һ��student�ṹ�����

	while (1)
	{
		printf("����ѧ����������������ѧ�ɼ���>");
		setbuf(stdin, NULL);    //��ջ�����
		scanf("%s%d%d", &stu.name, &stu.num, &stu.math);
		InsertNodeByHead(list, stu);    //��������

		printf("continue(Y/N)?\n");
		setbuf(stdin, NULL);
		int choose = getchar();    //�����Ƿ�Ҫ������ѡ��
		
		if (choose == 'N' || choose == 'n')    //�ж�
		{
			break;
		}
	}
	printfList(list);    //��ӡ���

	//InsertNodeByHead(list, 1);    //����ʹ��ͷ�巨���Ȳ�������ݷ����ں�
	//InsertNodeByHead(list, 2);    //
	//InsertNodeByHead(list, 3);    //����3���ڵ�

	//printfList(list);    //��������Ľ��

	//DeleteNodeByAppoin(list, 2);    //ɾ��1���ڵ�

	printf("delete(Y/N)?\n");
	setbuf(stdin, NULL);  
	int choose2 = getchar();    //�����Ƿ�Ҫɾ��Ԫ�ص�ѡ��
	if (choose2 == 'Y' || choose2 == 'y')    //�ж�
	{
		printf("����Ҫɾ���ĺ�����>");
		setbuf(stdin, NULL);
		int num = 0;
		scanf("%d", &num);
		DeleteNodeByAppoinNum(list, num);    //ִ��ɾ������
		printfList(list);    //��ӡɾ����Ľ��
	}

	return 0;
}




