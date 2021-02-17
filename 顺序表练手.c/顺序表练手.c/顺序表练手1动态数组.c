//����ʹ�õ���C���̳����SeqSize &L������L.data����д��ʽ����Ϊstruct SeqSize *L��L->data

#include <stdio.h>
#include <stdlib.h>

#define InitSize 5    //Ĭ����󳤶�

//����ṹ��
struct SeqList
{
	int* data;
	int MaxSize;
	int length;
};

//��ʼ��
void InitList(struct SeqList *L)
{
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->MaxSize = InitSize;
	L->length = 0;
}

//��̬��չ����
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

//��ӡ
void print(struct SeqList* L)
{
	printf("��ӡ˳���>\n");
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\t", L->data[i]);
	}
	printf("\n");
}

//��λ����
int Getnum(struct SeqList *L,int num)
{
	if (num < 1 || num > L->length)
	{
		printf("�������ֵΥ��������");
		return 0;
	}
	return L->data[num - 1];
}

//��ֵ����
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
//	printf("�������ֵ�ڴ�˳����в����ڣ�����");
//	return 0;
//}


int main()
{
	struct SeqList L;    //����˳���
	InitList(&L);

	IncreaseList(&L, 5);
	Init(&L);
	print(&L);

	int num = 0;
	printf("����Ҫ��ӡ���ݵ�λ��>");
	//printf("����Ҫ��ӡ���ݵ�ֵ��>");
	scanf("%d", &num);
	int a = Getnum(&L, num);
	printf("\nλ��Ϊ%d��������ֵ��%d", num,a);
	//printf("\n��ֵΪ%d������λ����%d", num, a);

	return 0;
}