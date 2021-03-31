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

//冒泡
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
	//定义桶数组和桶内元素的计数数组
	int bucket[5][5];
	int bucketsize[5];

	//初始化桶数组和桶的计数数组
	memset(bucket, 0, sizeof(bucket));
	memset(bucketsize, 0, sizeof(bucketsize));

	int i = 0;
	//把数组各元素放入对应的桶中
	for (i = 0; i < len; i++)
		bucket[arr[i] / 10][bucketsize[arr[i] / 10]++] = arr[i];

	//使用冒泡排序排列各桶
	for (i = 0; i < 5; i++)
		BubbleSort(bucket[i], bucketsize[i]);

	int j = 0, k = 0;
	//把桶内元素依次放入原函数
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





