#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int magicalString(int n) {
	char* s = (char*)malloc(sizeof(char) * (n + 10));
	//��ʼ��Ϊ0
	memset(s, 0, sizeof(s));
	//ͷ����Ԫ�س�ʼ��Ϊ122
	strcpy(s, "122");

	//s��һ�δ�����ַ�
	char ch = '1';
	//s�Ѵ���Ԫ�ص�����±�
	int cur = 2;
	//sԪ�ظ���
	int end = strlen(s);
		
	//s��δ��n��Ԫ��
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