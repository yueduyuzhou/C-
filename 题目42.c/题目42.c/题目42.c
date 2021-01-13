#include <stdio.h>

int main()
{
	int n = 3, i = 0;    //这里int相当于auto int
	for (i = 0; i < 3; i++)
	{
		printf("n = %d  ", n);
		{
			auto int m = 0;    //auto:在对应函数或块内变量有效
			printf("m = %d\n", m);
			m++;    //由于m是auto int型变量，每次进入{}区域会重新赋值
		}
		n++;    //在主函数内n一直有效
	}

	return 0;
}