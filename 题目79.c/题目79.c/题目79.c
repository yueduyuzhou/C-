#include <stdio.h>
#include <string.h>

void Swap(char* str1, char* str2)
{
	char str[20];
	strcpy(str, str1);
	strcpy(str1, str2);
	strcpy(str2, str);
}

void main()
{
	char str1[20];
	char str2[20];
	char str3[20];
	//����Ҫ�Ƚϵ��ַ���
	gets(str1);
	gets(str2);
	gets(str3);
	//�ֱ�Ƚ����ǵĴ�С���ٺ���������
	if (strcmp(str1, str2) > 0)
		Swap(str1, str2);
	if (strcmp(str2, str3) > 0)
		Swap(str2, str3);
	if (strcmp(str1, str2) > 0)
		Swap(str1, str2);
	printf("%s\n%s\n%s\n", str1, str2, str3);
}