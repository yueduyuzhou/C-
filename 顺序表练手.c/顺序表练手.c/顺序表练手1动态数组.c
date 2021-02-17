//由于使用的是C，教程里的SeqSize &L和例如L.data的书写形式均改为struct SeqSize *L和L->data

#include <stdio.h>
#include <stdlib.h>

#define InitSize 5    //默认最大长度

//定义结构体
struct SeqList
{
	int* data;
	int MaxSize;
	int length;
};

//初始化
void InitList(struct SeqList *L)
{
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->MaxSize = InitSize;
	L->length = 0;
}

//动态扩展数组
void IncreaseList(struct SeqList *L, int add)
{
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + add) * sizeof(int));
	L->MaxSize = L->MaxSize + add;
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	free(p);
}

void Init(struct SeqList* L)
{
	for (int i = 1; i <= 10; i++)
	{
		L->data[i - 1] = i + 99;
		L->length++;
	}
}

//打印
void print(struct SeqList* L)
{
	printf("打印顺序表：>\n");
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\t", L->data[i]);
	}
	printf("\n");
}

//按位查找
int Getnum(struct SeqList *L,int num)
{
	if (num < 1 || num > L->length)
	{
		printf("你输入的值违法！！！");
		return 0;
	}
	return L->data[num - 1];
}

//按值查找
//int Getnum(struct SeqList* L, int num)
//{
//	
//	for (int i = 0; i < L->length; i++)
//	{
//		if (num == L->data[i])
//		{
//			return i + 1;
//		}
//	}
//	printf("你输入的值在此顺序表中不存在！！！");
//	return 0;
//}


int main()
{
	struct SeqList L;    //创建顺序表
	InitList(&L);

	IncreaseList(&L, 5);
	Init(&L);
	print(&L);

	int num = 0;
	printf("输入要打印数据的位序；>");
	//printf("输入要打印数据的值；>");
	scanf("%d", &num);
	int a = Getnum(&L, num);
	printf("\n位序为%d的数据数值是%d", num,a);
	//printf("\n数值为%d的数据位序是%d", num, a);

	return 0;
}