#include <stdio.h>
#include <stdlib.h>

//������󳤶�
#define Max_size 30

//��ӡ����
void PrintArr(int* arr, int n)
{
	for (int j = 0; j < n; j++)
	{
		printf("%d\t", arr[j]);
	}
	printf("\n\n");
}


int main()
{
	int arr[Max_size] = { 0 };
	int m = 0, n = 0, i = 0;
	printf("��������Ԫ�ظ���:>");
	scanf("%d", &n);
	if (n > Max_size)
	{
		system("CLS");
		printf("��������ݲ��Ϸ�,����");
		main();
		return 0;
	}


	for (i = 0; i < n; i++)
	{
		printf("�����%d��Ԫ��:>", i + 1);
		scanf("%d", arr + i);
	}
	printf("\n\n��������:>");
	PrintArr(arr, n);

	printf("\n����Ҫƫ�Ƶ�Ԫ��λ��(ע��,����<%d):>", n);
	scanf("%d", &m);

	if (n % 2 == 0 && n / 2 == m)    //Ԫ�ظ���Ϊ˫����ƫ��λ���պ���Ԫ�ظ�����һ�룬ֱ�ӽ���
	{
		for (i = 0; i < m; i++)    //���±�Ϊ0��m-1��Ԫ���������±�Ϊm��n-1��Ԫ�ؽ���
		{
			int tmp = arr[i];
			arr[i] = arr[i + m];
			arr[i + m] = tmp;
		}
	}
	else
	{
		for (i = n - 1; i >= 0; i--)    //����Ԫ��ƫ��mλ
		{
			arr[i + m] = arr[i];
		}
		for (i = 0; i < m; i++)    //���m��Ԫ�طŵ���ǰ��
		{
			arr[i] = arr[i + n];
		}
	}

	printf("\n\n���:>");
	PrintArr(arr, n);

	return 0;
}