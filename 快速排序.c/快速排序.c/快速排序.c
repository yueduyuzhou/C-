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


//�Ż�1:�������ѡ��(����ѡ���м���)
int QuickOptimizeTmp(int* arr, int right)
{
	int left = 0;
	int k = 1;
	int max = 0, min = 0;
	int tmp = arr[left];

	while (left + 2 * k < right)    //ȡֵ�ںϷ���Χ�ڣ�ÿ������Ԫ��ȡһ�Σ�ѡ�����ֵ����Сֵ
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
	while (left + 2 * k < right)    //ȡֵ�ںϷ���Χ�ڣ�tmpȡ�����ӽ�(max + min)/2
	{
		if ((max + min) / 2 > arr[left + 2 * k] && arr[left + 2 * k] > arr[left + 2 * (k - 1)])
		{
			tmp = arr[left + 2 * k++];
		}
	}
	return tmp;
}
//�Ż�2:���鳤����10���ڲ��ò����������Ч(��)

void QuickSort(int* arr, int n)
{
	if (n < 2)    //����Ҫ��������鳤��С��2�ǣ�ֱ������
		return;

	int left = 0, right = n - 1;    //leftָ����Ԫ�أ�rightָ��βԪ��
	int flag = 1;    //flag  1���ƶ����±�  2���ƶ����±�
	int tmp = QuickOptimizeTmp(arr, n - 1);    //���(�ڿ�)
	while (left < right)
	{
		if (flag)
		{
			if (arr[right] < tmp)    //��Ԫ��С��tmp������ߵĿӣ��ı�flag��left����һ��������right����һ��
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
			if (arr[left] > tmp)    //��Ԫ�ش���tmp�����ұߵĿӣ��ı�flag��right����һ��������left����һ��
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
	arr[left] = tmp;    //��tmp����ʣ�µ�Ψһһ����
	QuickSort(arr, right);    //�������
	QuickSort(arr + right + 1, n - left - 1);    //�����ұ�
}

//��ӡ
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