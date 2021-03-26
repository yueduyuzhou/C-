#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define Max_size 15
#define Size1 7
#define Size2 8
//#define min(a,b) a<b? a:b

//�ϲ���������(�鲢����)
//int* MergeSort(int* arr1, int* arr2, int* arr)
//{
//	int i = 0, j = 0;
//	//while��ѭ��
//	while (i + j < Max_size)
//	{
//		if (arr1[i] < arr2[j] && i != Size1)
//		{
//			arr[i + j] = arr1[i];
//			i++;
//		}
//		else if (arr1[i] >= arr[j] && j != Size2)
//		{
//			arr[i + j] = arr2[j];
//			j++;
//		}
//
//	}
//	return arr;
//}

void PrintArr(int* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

//int main()
//{
//	int arr1[Size1] = { 3,38,44,50,52,63,78 };
//	int arr2[Size2] = { 5,15,36,47,48,53,69,77 };
//	int arr[Max_size] = { 0 };
//	MergeSort(arr1, arr2, arr);
//	PrintArr(arr1, Size1);
//	PrintArr(arr2, Size2);
//	PrintArr(arr, Max_size);
//	return 0;
//}

//void MargeSort(int* arr1, int n, int* arr2, int m)
//{
//	int arr[Max_size] = { 0 };
//	int i = 0, j = 0;
//	while (i < n && j < m)
//	{
//		if (arr1[i] < arr2[j])
//		{
//			arr[i + j] = arr1[i];
//			i++;
//		}
//		else if (arr1[i] >= arr2[j])
//		{
//			arr[i + j] = arr2[j];
//			j++;
//		}
//	}
//	if (i == n)
//	{
//		for (; j < m; j++)
//			arr[i + j] = arr2[j];
//	}
//	else if (j == m)
//	{
//		for (; i < n; i++)
//			arr[i + j] = arr1[i];
//	}
//	PrintArr(arr, Max_size);
//}
//
//int main()
//{
//	int arr1[Size1] = { 3,38,44,50,52,63,78 };
//	int arr2[Size2] = { 5,15,36,47,48,53,69,77 };
//	MargeSort(arr1, Size1, arr2, Size2);
//	PrintArr(arr1, Size1);
//	PrintArr(arr2, Size2);
//	return 0;
//}

//�ݹ�ʵ��
//void _MargeSort(int* arr, int* arrtmp, int start, int end)
//{
//	//�����С������
//	if (start >= end) return;
//
//	//��¼���������м��±�
//	int mid = start + (end - start) / 2;
//
//	int start1 = start, end1 = mid;
//	int start2 = mid + 1, end2 = end;
//
//	_MargeSort(arr, arrtmp, start1, end1);
//	_MargeSort(arr, arrtmp, start2, end2);
//
//	//arrtmp�ļ�����
//	int i = start;
//
//	//�鲢������Ȳ���
//	while (start1 <= end1 && start2 <= end2)
//	{
//		if (arr[start1] < arr[start2])
//			arrtmp[i++] = arr[start1++];
//		else
//			arrtmp[i++] = arr[start2++];
//	}
//
//	//����ʣ�µ�
//	while (start2 <= end2)
//		arrtmp[i++] = arr[start2++];
//	while (start1 <= end1)
//		arrtmp[i++] = arr[start1++];
//
//	memcpy(arr + start, arrtmp + start, (end + 1 - start) * sizeof(int));
//}
//
////����������
//void MargeSort(int* arr, int n)
//{
//	if (n < 2) return;
//	int arrtmp[Max_size] = { 0 };
//
//	//����������
//	_MargeSort(arr, arrtmp, 0, n - 1);
//}

//int min(int a, int b)
//{
//	return a < b ? a : b;
//	/*if (a < b)
//		return a;
//	else
//		return b;*/
//}

void MargeSort(int* arr, int n)
{
	//���鳤��С��2������
	if (n < 2) return;
	
	int mobile = 1;    //�ֶε�����
	int start = 0;    
	int* aa = arr;
	int* bb = (int*)malloc(n * sizeof(int));    //������ʱ�ռ�
	
	for (mobile = 1; mobile < n; mobile *= 2)
	{
		for (start = 0; start < n; start += mobile * 2)
		{
			int low = start;    
			int mid = min(start + mobile, n);    //���Ƿֶβ��������
			int max = min(start + mobile * 2, n);     //���Ƿֶβ��������
			
			int i = low;
			int start1 = low, end1 = mid;    //��ߵ�ͷ��β    
			int start2 = mid, end2 = max;    //�ұߵ�ͷ��β

			//����
			while (start1 < end1 && start2 < end2)
			{
				assert(bb);
				if (aa[start1] < aa[start2])
					bb[i++] = aa[start1++];
				else
					bb[i++] = aa[start2++];
			}
			while (start1 < end1)
				bb[i++] = aa[start1++];
			while (start2 < end2)
				bb[i++] = aa[start2++];
		}
		//����һ��ָ�����������ָ��
		int* tmp = aa; aa = bb; bb = tmp;
	}
	//������aa����ָ��arr���Ͱ�aaָ����������ݿ�����arr����
	if (aa != arr)
	{
		assert(aa);
		memcpy(arr, aa, n * sizeof(int));
		bb = aa;
	}
	free(bb);
	bb = NULL;
}

int main()
{
	int arr[Max_size] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	MargeSort(arr, Max_size);
	PrintArr(arr, Max_size);
	return 0;
}