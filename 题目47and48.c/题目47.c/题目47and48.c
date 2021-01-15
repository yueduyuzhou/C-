#include <stdio.h>

#define PI 3.14    //宏定义
#define eara(r) PI * r * r    //带参数的宏定义
#define volume(r) 2 * PI * r     //带参数的宏定义
#define PRINT printf ("-------------------------------------------------------------------------------------------\n\n");    //宏定义语句

int main()
{
	printf("1.圆面积 2.圆周长\n\n");
	printf("请选择；>");
	int i = 0;
	scanf("%d", &i);
	printf("\n\n输入半径；>");
	float r = 0;
	scanf("%f", &r);

	if (i == 1)
	{
		printf("\n\n圆面积是：>");
		printf("\n\n%f\n\n", eara(r));
	}
	else if (i == 2)
	{
		printf("\n\n圆周长是：>");
		printf("%f\n\n", volume(r));
	}
	else
	{
		PRINT;
		printf("输入的数据不合法，请重试；>\n\n");
		main();
	}

	return 0;
}