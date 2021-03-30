#include <stdio.h>    

//¡Ω≤„—≠ª∑√∞≈›≈≈–Ú
void BubbleSort1(int* arr,int n)
{
	if (n < 2)
	{
		printf(" ˝÷µÃ´∂Ã£°");
		return;
	}
	int i = 0, j = 0, tmp = 0, flag = 0;
	for (i = n; i > 0; i--)
	{
		flag = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
		if (flag == 0)
			return;
	}
}


//µ›πÈ√∞≈›
void BubbleSort2(int* arr, int n)
{
	if (n < 2)
	{
		printf(" ˝÷µÃ´∂Ã");
		return;
	}
	int i = 0, tmp = 0, flag = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			flag = 1;
			tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
		}
	}
	if (flag == 0)
		return;
	n--;
	if (n > 1)
	{
		BubbleSort2(arr, n);
	}
}

void PrintArr(int* arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int arr1[10] = { 8,45,163,5,4,84,63,21,58,16 };
	//int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	BubbleSort1(arr1, 10);
	PrintArr(arr1, 10); 

	//int arr2[10] = { 8,45,163,5,4,84,63,21,58,16 };
	int arr2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	BubbleSort2(arr2, 10);
	PrintArr(arr2, 10);

	return 0;
}
