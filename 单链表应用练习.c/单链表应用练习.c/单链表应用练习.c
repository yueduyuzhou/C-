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

////1.定义结构体
//struct Node
//{
//	int data;
//	struct Node* next;
//};

//2.创建链表(头)
struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));    //开辟空间
	assert(headNode);
	//headNode->data = 23;
	headNode->next = NULL;    //暂时指向空

	return headNode;
}

//3.创建节点
struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	assert(newNode);

	newNode->data = data;    //数据域赋初值
	newNode->next = NULL;    //暂时指向空

	return newNode;
}

//4.打印链表
void printfList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("name\tnum\tmath\n");

	while (pMove)    //从头寻找要打印的数据
	{
		printf("%s\t%d\t%d\n", pMove->data.name, pMove->data.num, pMove->data.math);
		pMove = pMove->next;    //向后跳一位
	}
	printf("\n\n");
}

//5.插入节点(头插法)
void InsertNodeByHead(struct Node* headNode, struct student data)
{
	struct Node* newNode = createNode(data);    //要插入，先创建节点

	newNode->next = headNode->next;    //使newNode的指针域指向原来headNode的下一个
	headNode->next = newNode;    //使头指向要插入的节点
}

//6.删除节点
int DeleteNodeByAppoinNum(struct Node* headNode, int num)
{
	struct Node* posNode = headNode->next;    //定义一个指针指向首元素
	struct Node* posNodeFront = headNode;    //定义一个指针指向posNode前一个指针

	if (posNode == NULL)    //还未遍历时，判断链表是否为空
	{
		printf("此链表为空\n");
	}
	else
	{
		while (posNode->data.num != num)    //遍历链表
		{
			posNodeFront = posNode;
			posNode = posNode->next;

			if (posNode == NULL)    //找不到要删除的数据，即该链表无次数据
			{
				printf("此链表没有该数据\n");
				return 0;    //返回主函数
			}
		}
		posNodeFront->next = posNode->next;    //使posNodeFront指向删除元素的下一个元素
		free(posNode);    //归还删除元素的空间
	}
	return 0;
}

int main()
{
	struct Node* list = createList();    //在主函数创建链表

	struct student stu;    //定义一个student结构体变量

	while (1)
	{
		printf("输入学生姓名，号数，数学成绩：>");
		setbuf(stdin, NULL);    //清空缓存区
		scanf("%s%d%d", &stu.name, &stu.num, &stu.math);
		InsertNodeByHead(list, stu);    //插入数据

		printf("continue(Y/N)?\n");
		setbuf(stdin, NULL);
		int choose = getchar();    //输入是否要继续的选择
		
		if (choose == 'N' || choose == 'n')    //判断
		{
			break;
		}
	}
	printfList(list);    //打印结果

	//InsertNodeByHead(list, 1);    //由于使用头插法，先插入的数据反而在后
	//InsertNodeByHead(list, 2);    //
	//InsertNodeByHead(list, 3);    //插入3个节点

	//printfList(list);    //输出插入后的结果

	//DeleteNodeByAppoin(list, 2);    //删除1个节点

	printf("delete(Y/N)?\n");
	setbuf(stdin, NULL);  
	int choose2 = getchar();    //输入是否要删除元素的选择
	if (choose2 == 'Y' || choose2 == 'y')    //判断
	{
		printf("输入要删除的号数：>");
		setbuf(stdin, NULL);
		int num = 0;
		scanf("%d", &num);
		DeleteNodeByAppoinNum(list, num);    //执行删除操作
		printfList(list);    //打印删除后的结果
	}

	return 0;
}




