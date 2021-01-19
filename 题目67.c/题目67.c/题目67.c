#include <stdio.h>

void swap(int* a, int* b)    //ָ�뵱�βν�����ֵ�������ں���������һ���������һ��ָ���ֵ
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", *(arr + i));
	}
	printf("\n");
}


int main()
{
	int n = 0, i = 0;
	int arr[20] = { 0 };
	printf("����������Ԫ�ظ���:>");
	scanf("%d", &n);
	
	printf("\n\n������Ԫ������:>");
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	PrintArr(arr, n);

	int max = 0, min = 0;
	for (i = 1; i < n; i++)    //�Ƚ�arr[0]���±�Ϊ1��n-1��Ԫ��
	{
		if (arr[max] < arr[i])    //��arr[max]<arr[i]ʱ����¼�±�i
			max = i;
		if (arr[min] > arr[i])    //��arr[min]>arr[i]ʱ����¼�±�i
			min = i;
	}
	if (max != 0)    //������Ԫ�ز�����Ԫ�أ�����arr[max]��arr[0]
		swap(arr, arr + max);
	if (min == 0)    //������һ��if���ܽ�����arr[0]��arr[max]������Ҫ��ʹmin=max
		min = max;
	if (min != n - 1)    //�����СԪ�ز���βԪ�أ�����arr[min]��arr[n-1]
		swap(arr + min, arr + n - 1);

	PrintArr(arr, n);

	return 0;
}