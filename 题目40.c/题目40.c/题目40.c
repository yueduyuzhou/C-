
#include <stdio.h>

//方法1.倒着输出
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//
//	printf("倒序前数组：>");    
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n\n");
//
//
//	printf("倒序后数组：>");
//	for (i = 9; i >= 0; i--)    
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


//方法2.翻转存放顺序
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1, left = 0, i = 0;

	printf("倒序前数组：>");
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");

	while (left < right)    //第一个与最后一个交换，第二个与倒数第二个交换，以此类推
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}

	printf("倒序后数组：>");
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}








