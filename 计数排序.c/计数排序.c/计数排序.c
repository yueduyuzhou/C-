#include <stdio.h>
#include <string.h>

//#define Max_size 20

//struct S
//{
//	int num;
//	int some;
//};
//
//int MinNum(int arr[])
//{
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < Max_size - 1; i++)
//	{
//		if (arr[i] <= arr[i + 1])
//			num = arr[i];
//	}
//	return num;
//}
//
//void CountSort(int* arr)
//{
//	int a = 0;
//	int b = 0;
//	struct S arr1[Max_size];
//}

int ArrMax(int arr[], int len)
{
	int i = 0;
	int max = 0;
	for (i = 0; i < len; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int ArrMin(int arr[], int len)
{
	int i = 0;
	int min = arr[0];
	for (i = 1; i < len; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

//void CountSort(int* arr, int len)
//{
//	int max = ArrMax(arr, len);
//	//����һ�������ֵ��һ�����飬�±�Ϊԭ�����ֵ������Ϊֵ�ĸ���
//	//int arrtmp[max + 1];
//	int arrtmp[10];
//	memset(arrtmp, 0, sizeof(arrtmp));
//
//	int i, j, k;
//	//��ʱ�������
//	for (i = 0; i < len; i++)
//		arrtmp[arr[i]]++;
//
//	i = 0;
//	for (j = 0; j < max + 1; j++)
//	{
//		for (k = 0; k < arrtmp[j]; k++)
//			arr[i++] = j;
//	}
//}

//�Ż�
void CountSort(int* arr, int len)
{
	int max = ArrMax(arr, len);
	int min = ArrMin(arr, len);
	//����һ���������ֵ����Сֵ��1�����飬�±�Ϊԭ�����ֵ������Ϊֵ�ĸ���
	//int arrtmp[max - min + 1];
	int arrtmp[20];
	//��ʱ�����ʼ��Ϊ0
	memset(arrtmp, 0, sizeof(arrtmp));

	int i, j, k;
	//��ʱ�������
	for (i = 0; i < len; i++)
		arrtmp[arr[i] - min]++;

	i = 0;
	for (j = 0; j < max - min + 1; j++)
	{
		for (k = 0; k < arrtmp[j]; k++)
			arr[i++] = j + min;
	}
}

void PrintArr(int* arr,int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

int main()
{
	//int arr[] = { 2,3,8,7,1,2,2,2,7,3,9,8,2,1,4,2,4,6,9,2 };
	//int arr[] = { 2,3,8,7,1,2,2,2,7,3 };
	int arr[] = { 101,105,101,110,109,106,106,101,110,107,108,104,104,105,102,101,103,110,109,103 };
	int Max_size = sizeof(arr) / sizeof(int);
	PrintArr(arr, Max_size);
	CountSort(arr, Max_size);
	PrintArr(arr, Max_size);
	return 0;
}