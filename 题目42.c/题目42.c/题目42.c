#include <stdio.h>

int main()
{
	int n = 3, i = 0;    //����int�൱��auto int
	for (i = 0; i < 3; i++)
	{
		printf("n = %d  ", n);
		{
			auto int m = 0;    //auto:�ڶ�Ӧ��������ڱ�����Ч
			printf("m = %d\n", m);
			m++;    //����m��auto int�ͱ�����ÿ�ν���{}��������¸�ֵ
		}
		n++;    //����������nһֱ��Ч
	}

	return 0;
}