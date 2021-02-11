#include <stdio.h>

int main()
{
	char str[30] = { '#' };
	char str1[20] = { '#' };
	char str2[10] = { '#' };
	char* p1, *p2, *p;
	printf("输入字符串1:>");
	gets(str1);
	printf("输入字符串2:>");
	gets(str2);

	p1 = str1;		//三个指针均指向三个字符串的首位置
	p2 = str2;
	p = str;

	while (*p1 != '\0')		//把str1拷入str
	{
		*p = *p1;
		p++, p1++;
	}
	while (*p2 != '\0')		//把str2拷入str
	{
		*p = *p2;
		p++, p2++;
	}

	printf("%s\n", str);
	return 0;
}