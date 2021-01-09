#include <stdio.h>
#include <windows.h>
#include <conio.h>

void main()
{
	int color;

	for (color = 0; color <= 15; color++)    //让颜色依次变化
	{
		printf("按下任意键改变颜色。\n");
		char waste = _getch();    //接收一个任意键，不用回车getch()函数自动结束
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | FOREGROUND_INTENSITY);  //color控制颜色，FOREGROUND_INTENSITY颜色使加强
	}
}