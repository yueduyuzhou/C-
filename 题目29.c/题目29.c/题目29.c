#include <stdio.h>

void Contrary(int i)
{
	int arr[5], m = 0;
	for (m = 0; m < 5; m++)
	{
		arr[m] = i % 10;   //������ĩλ��ʼ��λ��������
		i = i / 10;
	}
//	int left = 0;
//	while (left != right)    //��������Ħ10�������ͷ��ʼ����arr���飬��������������
//	{
//		int a = 0;
//		a = arr[left];
//		arr[left] = arr[right];
//		arr[right] = a;
//		left++;
//		right--;
//	}
	printf("����������");
	for (m = 0; m < 5; m++)   //��arr[0]��ʼ��ӡ
	{
		printf("%d", arr[m]);
	}
}

int main()
{
	int i = 0, n = 0, k = 0;
	scanf_s("%d", &i);
	k = i;
	while (i > 0)
	{
		i = i / 10;
		n++;
	}
	printf("�����ֵ��%dλ��\n", n);
	Contrary(k);
}