#include <stdio.h>

#define Max_size 15

//void QuickSort(int* arr, int left, int right, int n)
//{
//	int flag = 1;
//	while (left != right)
//	{
//		int tmp = arr[left];
//		if (flag)
//		{
//			if (arr[right] < tmp)
//			{
//				arr[left] = arr[right];
//				left++, flag = 0;
//			}
//			else
//			{
//				right--;
//			}
//		}
//		else
//		{
//			if (arr[left] > tmp)
//			{
//				arr[right] = tmp;
//				right--, flag = 1;
//			}
//			else
//			{
//				left++;
//			}
//		}
//	}
//	arr[left] = tmp;
//}


//优化1:中心轴的选择(尽量选择中间数)
int QuickOptimizeTmp(int* arr, int right)
{
	int left = 0;
	int k = 1;
	int max = 0, min = 0;
	int tmp = arr[left];

	while (left + 2 * k < right)    //取值在合法范围内，每隔两个元素取一次，选出最大值和最小值
	{
		if (arr[left + 2 * k] > tmp)
		{
			max = arr[left + 2 * k];
			k++;
		}
		if (arr[left + 2 * k] < tmp)
		{
			min = arr[left + 2 * k];
			k++;
		}
	}
	while (left + 2 * k < right)    //取值在合法范围内，tmp取尽量接近(max + min)/2
	{
		if ((max + min) / 2 > arr[left + 2 * k] && arr[left + 2 * k] > arr[left + 2 * (k - 1)])
		{
			tmp = arr[left + 2 * k++];
		}
	}
	return tmp;
}
//优化2:数组长度在10以内采用插入排序更高效(略)

void QuickSort(int* arr, int n)
{
	if (n < 2)    //当需要排序的数组长度小于2是，直接跳出
		return;

	int left = 0, right = n - 1;    //left指向首元素，right指向尾元素
	int flag = 1;    //flag  1：移动左下标  2：移动右下标
	int tmp = QuickOptimizeTmp(arr, n - 1);    //标记(挖坑)
	while (left < right)
	{
		if (flag)
		{
			if (arr[right] < tmp)    //右元素小于tmp，填左边的坑，改变flag，left右移一步。否则right左移一步
			{
				arr[left] = arr[right];
				left++, flag = 0;
			}
			else
			{
				right--;
			}
		}
		else
		{
			if (arr[left] > tmp)    //左元素大于tmp，填右边的坑，改变flag，right左移一步。否则left右移一步
			{
				arr[right] = arr[left];
				right--, flag = 1;
			}
			else
			{
				left++;
			}
		}
	}
	arr[left] = tmp;    //把tmp插入剩下的唯一一个坑
	QuickSort(arr, right);    //排序左边
	QuickSort(arr + right + 1, n - left - 1);    //排序右边
}

//打印
void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int arr[Max_size] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48 };

	PrintArr(arr, Max_size);
	QuickSort(arr, Max_size);
	PrintArr(arr, Max_size);

	return 0;
}