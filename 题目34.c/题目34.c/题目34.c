#include <stdio.h>
#include <windows.h>   //����SetConsoleTextAttributeҪ��

void No()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 16 | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
	printf("����һ��û�в�����û�з���ֵ�ĺ�����\n");
}


int Yes()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | 32 | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
	printf("����һ���в������з���ֵ�ĺ�����\n");
}

void main()   //���������������ֲ�ͬ����
{
	No(); 
	Yes();
}