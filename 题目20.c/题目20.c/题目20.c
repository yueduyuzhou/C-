#include <stdio.h>

int main()
{
	int i;
	double total_distance = 0,highly = 100;
	for (i = 0; i < 10; i++)
	{
		total_distance += highly;
		highly = highly / 2;
	}
	printf("������%lf�ס�\n", total_distance);
	printf("��ʮ�η����߶���%lf��\n", highly);
	return 0;
}
