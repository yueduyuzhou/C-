#include <stdio.h>
#include <windows.h>

int main()
{
	int color = 0;
	printf("�����ı���ɫ��0=��ɫ 1=��ɫ 2=��ɫ 3=����ɫ 4=��ɫ 5=��ɫ 6=��ɫ 7=��ɫ 8=��ɫ 9=����ɫ 10= ����ɫ 11=��ǳ��ɫ 12=����ɫ 13=����ɫ 14=����ɫ 15=����ɫ\n");
	printf("������һ�����֣�");
	scanf_s("%d", &color);   //��ȡ��������֣�������color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | FOREGROUND_INTENSITY);   //��������������ʾ��ɫ(ǰ��ɫ|��ǿ)
	printf("YueDuYuZhou 2021/1/3\n");
	main();   //�ظ�ִ��
	return 0;
}