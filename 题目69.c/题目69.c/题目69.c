#include <stdio.h>
#include <stdlib.h>

//��ͼ�ö��ѭ����д��δ�ɹ�
//int* InitArr(int n)
//{
//	int arr[n - 1];
//	//for (int i = 0, int j = 1; i < n; i++, j++)
//	//{
//	//	arr[i] = j;
//	//	if (j == 3)
//	//	{
//	//		j = 0;
//	//	}
//	//}
//	for (int i = 1; i <= n; i++)
//	{
//		arr[i - 1] = i;
//	}
//	return arr;
//}

int main()
{
	int n = 0;
	int i = 0, j = 0;
	int num = 0;
	printf("��������:>");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));    //����n��int�͵Ŀռ��arr
	for (j = 0; j < n; j++)
	{
		arr[j] = 0;
	}
	//int* arr = InitArr(n);

	j = 1;
	while (n - num != 1)    //�ж��Ƿ��в�ֹһ��Ԫ�أ��Ǽ�����������
	{
		for (i = 0; i < n; i++, j++)    //������ͷ��β���α���
		{
			//if (arr[i] % 3 == 0)
			//{
			//	arr[i] = 0;
			//	num++;
			//}
			while (arr[i] == 1)    //�ж��Ƿ��ѱ����
			{
				if (i == n - 1 && n - num != 1) i = 0;    //����жϵ������һ��Ԫ����δ����ǵ�Ԫ�ػ��в�ֻһ����������һ��Ԫ��    
				else i++;    //����i����1
			}
			if (j == 3)   //ÿ��ѭ����j=3ʱ����ǵ�ǰԪ��λ1����num����1��j��Ϊ0
			{
				arr[i] = 1;
				j = 0, num++;
			}
		}
	}
	for (j = 0; j < n; j++)    //����ʣ�µ�Ψһһ��δ����ǵ�Ԫ���±�
	{
		if (arr[j] == 0)
		{
			break;
		}
	}
	printf("����������%d��\n\n", j + 1);    //�������±�+1

	free(arr);    //�ͷ�arr��ָ����ѿ��ٿռ�
	arr = NULL;
	//�ظ�ִ��
	//main();
	return 0;
}

