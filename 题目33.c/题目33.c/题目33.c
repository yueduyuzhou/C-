#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	char waste;
	gotoxy(1, 1);
	printf("֣֣֣֣֣֣֣֣֣֣֣֣֣֣֣֣֣");
	Sleep(2000);   //������ͣ���룬��λ���룬1000���� = 1��
	gotoxy(2, 2);
	printf("����������������������������������");
	Sleep(2000);
	gotoxy(3, 3);
	printf("����������������������������������\n");
	printf("�������������");
	waste = _getch();
	system("cls");

	_cprintf("2021/1/2\n");
	printf("�������������");
	waste = _getch();
	system("cls");
	//clrscr();   //vs�����޷��øú���
	_cprintf("**************************************\n");
	return 0;
}