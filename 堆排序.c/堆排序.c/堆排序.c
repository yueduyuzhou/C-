#include <stdio.h>

#define Max_size 10

//����Ԫ�غ���
void swap(int* a, int *b)
{ int tmp = *a;*a = *b;*b = tmp; }

//ѭ��ʵ�ֶ�����
//void _heapSort(int* arr, int start, int end)
//{
//	int dad = start;    //��¼���ڵ�
//	int son = dad * 2 + 1;    //��¼�ӽڵ�
//
//	while (son <= end)
//	{
//		//��son��������ӽڵ��еĽϴ���
//		if (son + 1 <= end && arr[son] < arr[son + 1])
//			son++;
//
//		//�����ڵ�һ��ʼ�ʹ��������ӽڵ�ʱ��������ǰ�Ѿ��Ǵ󶥶ѣ�����ֱ������
//		if (arr[dad] > arr[son])
//			return;
//
//		//���򽻻����ӽڵ㣬��֮���ӽڵ����ڵ�ıȽ���׼��
//		swap(&arr[dad], &arr[son]);
//		dad = son;
//		son = dad * 2 + 1;
//	}
//}

void _heapSort(int* arr, int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;

	//�ӽڵ��±��ںϷ���Χ�ڣ�ѭ������
	if (son > end)
		return;
	//��son����ӽڵ�ֵ�ϴ���
	if (arr[son] < arr[son + 1] && son + 1 <= end)
		son++;
	//���ڵ�����ӽڵ��ʾ������ϣ�ֱ������
	if (arr[dad] > arr[son])
		return;
	//���򽻻����ӽڵ��ֵ���ټ������ӽڵ�����ڵ�Ƚ�
	swap(&arr[dad], &arr[son]);

	_heapSort(arr, son, end);

}

void HeapSort(int* arr, int len)
{
	int i = 0;
	//�����һ�����ڵ㿪ʼ����������Ԫ�ع���һ���󶥶�
	for (i = (len - 1) / 2; i >= 0; i--)
	{
		_heapSort(arr,i,len - 1);
	}

	//�Ѷ������һ��Ԫ�ؽ������ٹ����󶥶ѣ��ظ�ִ��ֱ���������
	for (i = len - 1; i > 0; i--)
	{
 		swap(&arr[0], &arr[i]);    //����
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