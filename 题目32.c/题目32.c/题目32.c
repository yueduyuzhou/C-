#include <stdio.h>
#include <windows.h>
#include <conio.h>

void main()
{
	int color;

	for (color = 0; color <= 15; color++)    //����ɫ���α仯
	{
		printf("����������ı���ɫ��\n");
		char waste = _getch();    //����һ������������ûس�getch()�����Զ�����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | FOREGROUND_INTENSITY);  //color������ɫ��FOREGROUND_INTENSITY��ɫʹ��ǿ
	}
}