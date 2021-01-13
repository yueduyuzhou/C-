#include <stdio.h>

void f()
{
	static int m = 0;    //用关键字static定义一个静态全局变量m
	int n = 0;
	printf("静态全局变量：>%d  动态局部变量：>%d\n", m, n);
	n++, m++;
}

int main()
{
	f();
	int i = 0;
	for (i = 0; i < 3; i++)    //输出3次，静态全局变量不变，动态局部变量每次跳出函数会释放掉
	{
		f();
	}

	return 0;
}
