#include <stdio.h>

int main()
{
	int n, m, i, b, s;
	int a = 0, c = 0;
	int arr[20] = { 0 };
	scanf_s("%d", &n);
	scanf_s("%d", &m);

	if (m > n)
	{
		s = m;
		m = n;
		n = s;
	}
	for (i = m; i != 1; i--)
	{
		if (m % i == 0)
		{
			if (n % i == 0)
			{
				printf("n��m�����Լ��Ϊ%d��\n", i);
				break;
			}
		}
	}
	if (i == 1)
	{
		printf("n��mû�����Լ��\n");
	}
	//����С��������������bug��
	for (i = 2; i <= m; i++)
	{
		if (n % i == 0) //�ж��Ƿ��ܱ�n����
		{
			if (m % i == 0)  //�ж��Ƿ��ܱ�m����
			{
				a = 0;
				arr[a] = i; //���湫Լ��
				a++;
				m = m / i;
				i = 2;
			}
		}
	}
	for (b = 0; b <= a; b++)
	{
		c = 1;
		c = c * arr[b]; //���й�Լ���Ļ�
	}
	printf("n��m����С������Ϊ%d��\n", c);

	return 0;
}