#include <stdio.h>

//两层循环选择排序
//void SelectSort1(int* arr, int n)
//{
//	if (n < 2) return;
//	int j = 0, tmp = 0;
//	for (int i = 0; i < n - 1; i++)    //一共进行n-1趟比较
//	{
//		//tmp = arr[i];
//		tmp = i;
//		for (j = i + 1; j < n; j++)    //每趟只需比较i+1到n-1之间的元素
//		{
//			if (arr[tmp] > arr[j])    //找出较小的元素，并标记它
//			{
//				tmp = j;
//			}
//		}
//		if (tmp != i)
//		{
//			int k = arr[tmp];
//			arr[tmp] = arr[i];
//			arr[i] = k;
//		}
//	}
//}

//优化两层循环选择排序,每一次扫描，同时标记最大和最小数组元素，再一趟末尾最大元素上升，最小元素下沉
void SelectSort1(int* arr, int n)
{
	if (n < 2) return;

	int j = 0;
	int maxtmp = 0, mintmp = 0;
	int left = 0, right = n - 1;
	while (left < right)
	{
		maxtmp = mintmp = left;
		for (j = left + 1; j < right + 1; j++)    //每趟只需判断arr[left]与下标为left+1到right的元素
		{
			if (arr[mintmp] > arr[j])    //记录最小值下标
				mintmp = j;
			if (arr[maxtmp] < arr[j])    //记录最大值下标
				maxtmp = j;
		}
		if (mintmp != left)
		{
			int tmp = arr[mintmp];
			arr[mintmp] = arr[left];
			arr[left] = tmp;
		}
		if (maxtmp == left)    //由于在上一个if判断中arr[left]可能被改变，重新将被标记的最大值换回来
			maxtmp = mintmp;
		if (maxtmp != right)
		{
			int tmp = arr[maxtmp];
			arr[maxtmp] = arr[right];
			arr[right] = tmp;
		}

		left++, right--;
	}

}

//递归选择排序
//void SelectSort2(int* arr, int n)
//{
//	if (n < 2) return;
//	int i = 0, tmp = 0;
//	for (i = 0; i < n - 1; i++)    //比较arr[tmp]和i到n - 1之间的元素
//	{
//		if (arr[tmp] > arr[i + 1])
//		{
//			tmp = i + 1;
//		}
//	}
//	if (tmp != 0)    //arr[0]递归前的arr[1]，所以基准一直为arr[0]
//	{
//		int k = arr[tmp];
//		arr[tmp] = arr[0];
//		arr[0] = k;
//	}
//	SelectSort2(arr + 1, --n);    //每递归一次，数组长度减一，即数组首元素向后移动一位，
//}

//优化递归选择排序
void SelectSort2(int* arr, int n)
{
	if (n < 2) return;
	int i = 0;
	int maxtmp = 0, mintmp = 0;
	int left = 0, right = n - 1;

		for (i = 1; i < right + 1; i++)    //比较i-1到right之间的元素
		{
			if (arr[mintmp] > arr[i])
				mintmp = i;
			if (arr[maxtmp] < arr[i])
				maxtmp = i;
		}
		if (mintmp != left)  
		{
			int k = arr[mintmp];
			arr[mintmp] = arr[left];
			arr[left] = k;
		}

		if (maxtmp == left)
			maxtmp = mintmp;
		if (maxtmp != right)
		{
			int k = arr[maxtmp];
			arr[maxtmp] = arr[right];
			arr[right] = k;
		}

		n -= 2;    //一趟比较搞定两个元素
		SelectSort2(arr + 1, n);    //每递归一次，数组长度减一，即数组首元素向后移动一位
}

//打印
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
	int arr1[10] = { 3,21,16,4,84,6,51,44,98,10 };
	//int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	SelectSort1(arr1, 10);
	PrintArr(arr1, 10);

	int arr2[10] = { 3,21,16,4,84,6,51,44,98,10 };
	//int arr2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	SelectSort2(arr2, 10);
	PrintArr(arr2,10);
	return 0;
}