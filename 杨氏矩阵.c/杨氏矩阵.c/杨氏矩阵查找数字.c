#include <stdio.h>

int FindNum(int arr[3][3], int k, int* px, int* py)    //��ָ�������������x��y
{
	int x = 0, y = *py - 1;
	while (x <= *px-1 && y >= 0)    //�Ӿ������Ͻǿ�ʼ�����½�Ѱ��
	{
		if (arr[x][y] > k)
		{
			y--;    //ÿ�β����ϸɵ�һ��
		}
		else if (arr[x][y] < k)
		{
			x++;    //ÿ�β����ϸɵ�һ��
		}
		else
		{
			*px = x;    //��ֵ������x
			*py = y;    //��ֵ������y
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };    //�������Ͼ���
	int k = 0, x = 3, y = 3;

	printf("����һ������");
	scanf("%d", &k);    //����һ��k
	int ret = FindNum(arr, k, &x, &y);    //�Զ�����Һ���
	if (ret == 1)    //�ж�
	{
		printf("�ҵ���\n");
		printf("�±��ǣ�%d,%d����",x, y);
	}
	else
	{
		printf ("�Ҳ���\n");
	}

	return 0;
}