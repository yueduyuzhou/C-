#include <stdio.h>

#define PI 3.14    //�궨��
#define eara(r) PI * r * r    //�������ĺ궨��
#define volume(r) 2 * PI * r     //�������ĺ궨��
#define PRINT printf ("-------------------------------------------------------------------------------------------\n\n");    //�궨�����

int main()
{
	printf("1.Բ��� 2.Բ�ܳ�\n\n");
	printf("��ѡ��>");
	int i = 0;
	scanf("%d", &i);
	printf("\n\n����뾶��>");
	float r = 0;
	scanf("%f", &r);

	if (i == 1)
	{
		printf("\n\nԲ����ǣ�>");
		printf("\n\n%f\n\n", eara(r));
	}
	else if (i == 2)
	{
		printf("\n\nԲ�ܳ��ǣ�>");
		printf("%f\n\n", volume(r));
	}
	else
	{
		PRINT;
		printf("��������ݲ��Ϸ��������ԣ�>\n\n");
		main();
	}

	return 0;
}