#include <stdio.h>

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
	int arr[10] = { 0 };
	//int arr[10] = { 5,4,16,168,46,21,3,46,8,23 };
	int tmp = 0, i = 0, j = 0;
	printf("输入数组首元素:>");
	scanf("%d", arr);
	
	for (j = 0; j < 9; j++)
	{
		PrintArr(arr, 10);    //打印每一次插入后的结果
		printf("输入要插入的数据:>");
		scanf("%d", &tmp);
		for (i = j; i >= 0; i--)
		{
			if (i == 0)    //与首元素比较
			{
				if (arr[0] < tmp)    //首元素小于tmp，插在首元素后一位
					arr[1] = tmp;
				if (arr[0] > tmp)    //否则首元素向后移动一位，然后插在首位
				{
					arr[1] = arr[0];
					arr[0] = tmp;
				}
				break;    //插入完成后跳出
			}

			if (arr[i] < tmp)    //比较下标为i的元素和tmp，小于，插在i的后一位
			{
				arr[i + 1] = tmp;
				break;
			}
			if (arr[i] > tmp)    //大于，i后移一位
			{
				arr[i + 1] = arr[i];
			}
		}
	}
	printf("\n\n插入完成后完整数组为:>");    //打印最终结果
	PrintArr(arr, 10);

	return 0;
}