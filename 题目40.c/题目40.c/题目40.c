
#include <stdio.h>

//����1.�������
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//
//	printf("����ǰ���飺>");    
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n\n");
//
//
//	printf("��������飺>");
//	for (i = 9; i >= 0; i--)    
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


//����2.��ת���˳��
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1, left = 0, i = 0;

	printf("����ǰ���飺>");
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");

	while (left < right)    //��һ�������һ���������ڶ����뵹���ڶ����������Դ�����
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}

	printf("��������飺>");
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}








