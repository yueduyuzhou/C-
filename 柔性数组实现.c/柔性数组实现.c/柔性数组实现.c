#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct flexibleArr
{
	int n;
	int arr[];
};

struct flexibleArr2
{
	int n; 
	int* spp;
};

void PrintArr(struct flexibleArr* sp, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", sp->arr[i]);
	}
	printf("\n\n");
}

void PrintArr2 (struct flexibleArr2* sp, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", sp->spp[i]);
	}
	printf("\n\n");
}

//����һ
//int main()
//{
//	int i = 0;
//	struct flexibleArr* sp = (struct flexibleArr*)malloc(sizeof(struct flexibleArr) + 5 * sizeof(int));
//	//�ȸ�������������5��int
//	sp->n = 23;
//	for (i = 0; i < 5; i++)
//	{
//		sp->arr[i] = i;
//	}
//	PrintArr(sp, 5);
//
//	//������������
//	struct flexibleArr* str = realloc(sp, 44);    //������������5��int������24->44
//	if (str != NULL)
//	{
//		sp = str;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		sp->arr[i] = i;
//	}
//	PrintArr(sp, 10);
//	printf("%d\n", sp->n);
//
//	//�ͷ�
//	free(sp);
//	sp = NULL;
//
//	return 0;
//}


//������
int main()
{
	int i = 0;
	struct flexibleArr2* sp = (struct flexibleArr2*)malloc(sizeof(struct flexibleArr2));
	if (sp != NULL)
	{
		sp->spp = (int*)malloc(5 * sizeof(int));
		assert(sp->spp && sp);
	}
	for (i = 0; i < 5; i++)
	{
		sp->spp[i] = i;
	}
	PrintArr2(sp, 5);

	realloc(sp->spp, 10 * sizeof(int));
	if (sp->spp != NULL)
	{
		for (i = 5; i < 10; i++)
		{
			sp->spp[i] = i;
		}
	}
	PrintArr2(sp, 10);

	//�ͷ�
	free(sp->spp);
	sp->spp = NULL;
	free(sp);
	sp = NULL;
	return 0;
}



