#include <stdio.h>

void main()
{
	int i = 0, n = 0, star = 0;
	
	for (n = 1; n <= 7; n++)   //��������
	{
		for (i = abs(n - 4); i >= 1; i--)   //ÿ�пո���=����-4�ľ���ֵ
		{
			printf(" ");
		}
		for (star = 1; star <= 7 - 2 * abs(n - 4); star++)   //ÿ��*��=7-2*�ո���
		{
			printf("%c", '*');
		}
		printf("\n");   //����
	}
}