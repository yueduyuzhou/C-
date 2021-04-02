#include <stdio.h>

//����ѭ��ѡ������
//void SelectSort1(int* arr, int n)
//{
//	if (n < 2) return;
//	int j = 0, tmp = 0;
//	for (int i = 0; i < n - 1; i++)    //һ������n-1�˱Ƚ�
//	{
//		//tmp = arr[i];
//		tmp = i;
//		for (j = i + 1; j < n; j++)    //ÿ��ֻ��Ƚ�i+1��n-1֮���Ԫ��
//		{
//			if (arr[tmp] > arr[j])    //�ҳ���С��Ԫ�أ��������
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

//�Ż�����ѭ��ѡ������,ÿһ��ɨ�裬ͬʱ���������С����Ԫ�أ���һ��ĩβ���Ԫ����������СԪ���³�
void SelectSort1(int* arr, int n)
{
	if (n < 2) return;

	int j = 0;
	int maxtmp = 0, mintmp = 0;
	int left = 0, right = n - 1;
	while (left < right)
	{
		maxtmp = mintmp = left;
		for (j = left + 1; j < right + 1; j++)    //ÿ��ֻ���ж�arr[left]���±�Ϊleft+1��right��Ԫ��
		{
			if (arr[mintmp] > arr[j])    //��¼��Сֵ�±�
				mintmp = j;
			if (arr[maxtmp] < arr[j])    //��¼���ֵ�±�
				maxtmp = j;
		}
		if (mintmp != left)
		{
			int tmp = arr[mintmp];
			arr[mintmp] = arr[left];
			arr[left] = tmp;
		}
		if (maxtmp == left)    //��������һ��if�ж���arr[left]���ܱ��ı䣬���½�����ǵ����ֵ������
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

//�ݹ�ѡ������
//void SelectSort2(int* arr, int n)
//{
//	if (n < 2) return;
//	int i = 0, tmp = 0;
//	for (i = 0; i < n - 1; i++)    //�Ƚ�arr[tmp]��i��n - 1֮���Ԫ��
//	{
//		if (arr[tmp] > arr[i + 1])
//		{
//			tmp = i + 1;
//		}
//	}
//	if (tmp != 0)    //arr[0]�ݹ�ǰ��arr[1]�����Ի�׼һֱΪarr[0]
//	{
//		int k = arr[tmp];
//		arr[tmp] = arr[0];
//		arr[0] = k;
//	}
//	SelectSort2(arr + 1, --n);    //ÿ�ݹ�һ�Σ����鳤�ȼ�һ����������Ԫ������ƶ�һλ��
//}

//�Ż��ݹ�ѡ������
void SelectSort2(int* arr, int n)
{
	if (n < 2) return;
	int i = 0;
	int maxtmp = 0, mintmp = 0;
	int left = 0, right = n - 1;

		for (i = 1; i < right + 1; i++)    //�Ƚ�i-1��right֮���Ԫ��
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

		n -= 2;    //һ�˱Ƚϸ㶨����Ԫ��
		SelectSort2(arr + 1, n);    //ÿ�ݹ�һ�Σ����鳤�ȼ�һ����������Ԫ������ƶ�һλ
}

//��ӡ
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