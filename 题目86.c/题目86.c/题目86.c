#include <stdio.h>

int main()
{
	char str[30] = { '#' };
	char str1[20] = { '#' };
	char str2[10] = { '#' };
	char* p1, *p2, *p;
	printf("�����ַ���1:>");
	gets(str1);
	printf("�����ַ���2:>");
	gets(str2);

	p1 = str1;		//����ָ���ָ�������ַ�������λ��
	p2 = str2;
	p = str;

	while (*p1 != '\0')		//��str1����str
	{
		*p = *p1;
		p++, p1++;
	}
	while (*p2 != '\0')		//��str2����str
	{
		*p = *p2;
		p++, p2++;
	}

	printf("%s\n", str);
	return 0;
}