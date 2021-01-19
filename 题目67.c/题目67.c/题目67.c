#include <stdio.h>

void swap(int* a, int* b)    //指针当形参交换数值，可以在函数内设置一个整数存放一个指针的值
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
	printf("请输入数组元素个数:>");
	scanf("%d", &n);
	
	printf("\n\n请输入元素数据:>");
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	PrintArr(arr, n);

	int max = 0, min = 0;
	for (i = 1; i < n; i++)    //比较arr[0]与下标为1到n-1的元素
	{
		if (arr[max] < arr[i])    //当arr[max]<arr[i]时，记录下标i
			max = i;
		if (arr[min] > arr[i])    //当arr[min]>arr[i]时，记录下标i
			min = i;
	}
	if (max != 0)    //如果最大元素不是首元素，交换arr[max]与arr[0]
		swap(arr, arr + max);
	if (min == 0)    //由于上一个if可能交换了arr[0]与arr[max]，所以要先使min=max
		min = max;
	if (min != n - 1)    //如果最小元素不是尾元素，交换arr[min]与arr[n-1]
		swap(arr + min, arr + n - 1);

	PrintArr(arr, n);

	return 0;
}