#include <stdio.h> 
//计算球体积部分有bug(r = 2.35)
#define PI 3.14    //宏定义

double CircleArea(double r)    
{
	double result = PI * r * r;    //计算圆面积
	return result;
}

double CircleVolume(double r)
{
	double result = 2 * PI * r;    //计算圆体积
	return result;
}

double BallArea(double r)
{
	double result = 4 * PI * r * r;    //计算球面积
	return result;
}

double BallVolume(double r)
{
	double result = 3 * PI * r * r * r / 4;    //计算球体积
	return result;
}

int main()
{
	printf("1.圆面积 2.圆周长 3.球面积 4.球体积\n");
	printf("请选择：>");
	int choose = 0, waste = 0;
	waste = scanf("%d", &choose);
	if (choose > 4 || choose < 1)    //判断数据是否符合程序
	{
		printf("输入的数据非法，重新开始\n");
		main();  
	}
	else if (choose == 1)
	{
		printf("圆半径：>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = CircleArea(r);
		printf("\n结果：>%lf\n", result);
	}
	else if (choose == 2)
	{
		printf("圆半径：>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = CircleVolume(r);
		printf("\n结果：>%lf\n", result);
	}
	else if (choose == 3)
	{
		printf("球半径：>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = BallArea(r);
		printf("\n结果：>%lf\n", result);
	}
	else
	{
		printf("球半径：>");
		double r = 0;
		waste = scanf("%lf", &r);
		double result = BallVolume(r);
		printf("\n结果：>%lf\n", result);
	}

	return 0;
}