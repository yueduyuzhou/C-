#include <stdio.h>

//static int num = 23;    //加static后num无法被另一个.c文件调用
int num = 23;    //定义全局变量num

void main()
{
	f();
	//printf("%d", a);
}