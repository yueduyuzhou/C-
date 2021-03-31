#include <stdio.h>
#include <string.h>

int Max(int arr[], int len)
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

int Min(int arr[], int len)
{
	int i = 0;
	int min = 0;
	for (i = 0; i < len; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//ð��
void BubbleSort(int* bucket, int n)
{
	int i = 0, j = 0;
	for (i = n - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if (bucket[j] > bucket[j + 1])
				swap(&bucket[j], &bucket[j + 1]);
		}
	}
}

void BucketSort(int* arr, int len)
{
	//����Ͱ�����Ͱ��Ԫ�صļ�������
	int bucket[5][5];
	int bucketsize[5];

	//��ʼ��Ͱ�����Ͱ�ļ�������
	memset(bucket, 0, sizeof(bucket));
	memset(bucketsize, 0, sizeof(bucketsize));

	int i = 0;
	//�������Ԫ�ط����Ӧ��Ͱ��
	for (i = 0; i < len; i++)
		bucket[arr[i] / 10][bucketsize[arr[i] / 10]++] = arr[i];

	//ʹ��ð���������и�Ͱ
	for (i = 0; i < 5; i++)
		BubbleSort(bucket[i], bucketsize[i]);

	int j = 0, k = 0;
	//��Ͱ��Ԫ�����η���ԭ����
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < bucketsize[i]; j++)
			arr[k++] = bucket[i][j];
	}
}

void PrintArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int arr[] = { 21,3,30,44,15,36,6,10,9,19,25,48,5,23,47 };
	int len = sizeof(arr) / sizeof(int);
	PrintArr(arr, len);

	BucketSort(arr, len);
	PrintArr(arr, len);
	return 0;
}





