#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0, n = 0, sum = 0;
	printf("100���ڵ������У�");
	for (i = 2; i <= 100; i++)    //��1��100��Ѱ��
	{ 
		int flag = 0;    //����ǣ����ñ��
		for (n = 2; n <= sqrt(i); n++)
		{
			if (i % n == 0)    //�ж�
			{
				flag = 1;
				break;    //����
			}
		}
		if (flag == 0)
		{
			printf("%d ", i);
			sum += i;    //���
		}
	}
	printf("\n��Ϊ��");
	printf("%d\n", sum);
	return 0;
}