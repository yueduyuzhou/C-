#include <stdio.h>

void Factor()
{
	int sum = 0, i = 0, a = 0;
	for (i = 1; i <= 1000; i++)
	{
		for (a = 1; a < i; a++)  //�����������
		{
			if (i % a == 0)  //�ж��Ƿ�Ϊ����
			{
				sum = sum + a;
			}
		}
		
		if (i == sum)
		{
			printf("%d	", i);
		}
		sum = 0;
	}
}

int main()
{
	Factor();

	return 0;
}