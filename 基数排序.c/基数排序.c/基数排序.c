#include <stdio.h>

void PrintArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
}

int Max(int* arr,int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int Size(int num)
{
	int size = 0;
	while (num > 0)
	{
		size++;
		num /= 10;
	}
	return size;
}

void _RadixSort(int* arr, int len, int b)
{
	int radix[10][5] = { 0 };
	int i, j;
	for (i = 0; i < len; i++)
	{
		int k = 0;
		for (j = 0; j < len; j++)
		{
			if (arr[j] / b % 10 == i && arr[j] != -1)
			{
				radix[i][k++] = arr[j];
				arr[j] = -1;
			}
		}
	}
	j = 0;
	for (i = 0; i < len; i++)
	{
		int k = 0;
		while (radix[i][k] != 0)
			arr[j++] = radix[i][k++];
	}
}

void RadixSort(int* arr, int len)
{
	int a = 0, b = 1;
	int size = Size(Max(arr, len));
	while (a++ < 3)
	{
		PrintArr(arr, len);
		_RadixSort(arr, len, b);
		b *= 10;
	}
}

int main()
{
	int arr[10] = { 144,203,6,905,47,215,836,26,527,602 };
	RadixSort(arr, sizeof(arr) / sizeof(int));
	PrintArr(arr, sizeof(arr) / sizeof(int));

	return 0;	
}