#include <stdio.h> 
//���������������bug(r = 2.35)
#define PI 3.14    //�궨��

double CircleArea(double r)    
{
	double result = PI * r * r;    //����Բ���
	return result;
}

double CircleVolume(double r)
{
	double result = 2 * PI * r;    //����Բ���
	return result;
}

double BallArea(double r)
{
	double result = 4 * PI * r * r;    //���������
	return result;
}

double BallVolume(double r)
{
	double result = 3 * PI * r * r * r / 4;    //���������
	return result;
}

int main()
{
	printf("1.Բ��� 2.Բ�ܳ� 3.����� 4.�����\n");
	printf("��ѡ��>");
	int choose = 0, waste = 0;
	waste = scanf("%d", &choose);
	if (choose > 4 || choose < 1)    //�ж������Ƿ���ϳ���
	{
		printf("��������ݷǷ������¿�ʼ\n");
		main();  
	}
	else if (choose == 1)
	{
		printf("Բ�뾶��>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = CircleArea(r);
		printf("\n�����>%lf\n", result);
	}
	else if (choose == 2)
	{
		printf("Բ�뾶��>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = CircleVolume(r);
		printf("\n�����>%lf\n", result);
	}
	else if (choose == 3)
	{
		printf("��뾶��>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = BallArea(r);
		printf("\n�����>%lf\n", result);
	}
	else
	{
		printf("��뾶��>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = BallVolume(r);
		printf("\n�����>%lf\n", result);
	}

	return 0;
}