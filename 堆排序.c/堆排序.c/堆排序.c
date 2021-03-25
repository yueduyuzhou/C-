#include <stdio.h>

#define Max_size 10

//交换元素函数
void swap(int* a, int *b)
{ int tmp = *a;*a = *b;*b = tmp; }

//循环实现堆排序
//void _heapSort(int* arr, int start, int end)
//{
//	int dad = start;    //记录父节点
//	int son = dad * 2 + 1;    //记录子节点
//
//	while (son <= end)
//	{
//		//让son标记两个子节点中的较大者
//		if (son + 1 <= end && arr[son] < arr[son + 1])
//			son++;
//
//		//当父节点一开始就大于两个子节点时，由于先前已经是大顶堆，所以直接跳出
//		if (arr[dad] > arr[son])
//			return;
//
//		//否则交换父子节点，再之后子节点和孙节点的比较做准备
//		swap(&arr[dad], &arr[son]);
//		dad = son;
//		son = dad * 2 + 1;
//	}
//}

void _heapSort(int* arr, int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;

	//子节点下标在合法范围内，循环继续
	if (son > end)
		return;
	//让son标记子节点值较大者
	if (arr[son] < arr[son + 1] && son + 1 <= end)
		son++;
	//父节点大于子节点表示调整完毕，直接跳出
	if (arr[dad] > arr[son])
		return;
	//否则交换父子节点的值，再继续让子节点与孙节点比较
	swap(&arr[dad], &arr[son]);

	_heapSort(arr, son, end);

}

void HeapSort(int* arr, int len)
{
	int i = 0;
	//从最后一个父节点开始调整，所有元素构建一个大顶堆
	for (i = (len - 1) / 2; i >= 0; i--)
	{
		_heapSort(arr,i,len - 1);
	}

	//堆顶与最后一个元素交换，再构建大顶堆，重复执行直到排序完成
	for (i = len - 1; i > 0; i--)
	{
 		swap(&arr[0], &arr[i]);    //交换
		_heapSort(arr, 0, i - 1);
	}
}

void PrintArr(int arr[])
{
	for (int i = 0; i < Max_size; i++)
	{ printf("%d\t", arr[i]); }

	printf("\n\n");
}

int main()
{
	int arr[Max_size] = { 31,2,1,85,3,48,68,12,23,25 };
	PrintArr(arr);
	HeapSort(arr,Max_size);
	PrintArr(arr);
	return 0;
}