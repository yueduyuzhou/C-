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
	printf("Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£Ö£");
	Sleep(2000);   //³ÌĞòÔİÍ£Á½Ãë£¬µ¥Î»ºÁÃë£¬1000ºÁÃë = 1Ãë
	gotoxy(2, 2);
	printf("ÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄÔÄ");
	Sleep(2000);
	gotoxy(3, 3);
	printf("ÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓîÓî\n");
	printf("°´ÈÎÒâ¼üÇåÆÁ£º");
	waste = _getch();
	system("cls");

	_cprintf("2021/1/2\n");
	printf("°´ÈÎÒâ¼üÇåÆÁ£º");
	waste = _getch();
	system("cls");
	//clrscr();   //vs»·¾³ÎŞ·¨ÓÃ¸Ãº¯Êı
	_cprintf("**************************************\n");
	return 0;
}