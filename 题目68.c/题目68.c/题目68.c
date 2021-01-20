#include <stdio.h>
#include <stdlib.h>

//数组最大长度
#define Max_size 30

//打印数组
void PrintArr(int* arr, int n)
{
	for (int j = 0; j < n; j++)
	{
		printf("%d\t", arr[j]);
	}
	printf("\n\n");
}


int main()
{
	int arr[Max_size] = { 0 };
	int m = 0, n = 0, i = 0;
	printf("输入数组元素个数:>");
	scanf("%d", &n);
	if (n > Max_size)
	{
		system("CLS");
		printf("输入的数据不合法,重来");
		main();
		return 0;
	}


	for (i = 0; i < n; i++)
	{
		printf("输入第%d个元素:>", i + 1);
		scanf("%d", arr + i);
	}
	printf("\n\n完整数组:>");
	PrintArr(arr, n);

	printf("\n输入要偏移的元素位数(注意,个数<%d):>", n);
	scanf("%d", &m);

	if (n % 2 == 0 && n / 2 == m)    //元素个数为双数，偏移位数刚好是元素个数的一半，直接交换
	{
		for (i = 0; i < m; i++)    //从下标为0到m-1的元素依次与下标为m到n-1的元素交换
		{
			int tmp = arr[i];
			arr[i] = arr[i + m];
			arr[i + m] = tmp;
		}
	}
	else
	{
		for (i = n - 1; i >= 0; i--)    //所有元素偏移m位
		{
			arr[i + m] = arr[i];
		}
		for (i = 0; i < m; i++)    //最后m个元素放到最前面
		{
			arr[i] = arr[i + n];
		}
	}

	printf("\n\n结果:>");
	PrintArr(arr, n);

	return 0;
}