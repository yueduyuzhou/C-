#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int magicalString(int n) {
	char* s = (char*)malloc(sizeof(char) * (n + 10));
	//初始化为0
	memset(s, 0, sizeof(s));
	//头三个元素初始化为122
	strcpy(s, "122");

	//s下一次存入的字符
	char ch = '1';
	//s已存入元素的最后下标
	int cur = 2;
	//s元素个数
	int end = strlen(s);
		
	//s还未到n个元素
	while (end < n)
	{
		for (int i = 0; i < s[cur] - '0'; i++)
		{
			s[end++] = ch;
		}
		cur++;
		ch = '1' + '2' - ch;
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			res++;
		}
	}

	return res;
}

int main()
{

	magicalString(6);

	return 0;
}