#include <stdio.h>
#include <windows.h>   //调用SetConsoleTextAttribute要用

void No()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 16 | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
	printf("这是一个没有参数，没有返回值的函数！\n");
}


int Yes()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | 32 | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
	printf("这是一个有参数，有返回值的函数！\n");
}

void main()   //在主函数调用两种不同函数
{
	No(); 
	Yes();
}