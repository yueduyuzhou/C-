#include <stdio.h>

void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", *(arr + i));
	}
	printf("\n");
}


int main()
{
	int arr[10] = { 0 };
	//int arr[10] = { 5,4,16,168,46,21,3,46,8,23 };
	int tmp = 0, i = 0, j = 0;
	printf("����������Ԫ��:>");
	scanf("%d", arr);
	
	for (j = 0; j < 9; j++)
	{
		PrintArr(arr, 10);    //��ӡÿһ�β����Ľ��
		printf("����Ҫ���������:>");
		scanf("%d", &tmp);
		for (i = j; i >= 0; i--)
		{
			if (i == 0)    //����Ԫ�رȽ�
			{
				if (arr[0] < tmp)    //��Ԫ��С��tmp��������Ԫ�غ�һλ
					arr[1] = tmp;
				if (arr[0] > tmp)    //������Ԫ������ƶ�һλ��Ȼ�������λ
				{
					arr[1] = arr[0];
					arr[0] = tmp;
				}
				break;    //������ɺ�����
			}

			if (arr[i] < tmp)    //�Ƚ��±�Ϊi��Ԫ�غ�tmp��С�ڣ�����i�ĺ�һλ
			{
				arr[i + 1] = tmp;
				break;
			}
			if (arr[i] > tmp)    //���ڣ�i����һλ
			{
				arr[i + 1] = arr[i];
			}
		}
	}
	printf("\n\n������ɺ���������Ϊ:>");    //��ӡ���ս��
	PrintArr(arr, 10);

	return 0;
}