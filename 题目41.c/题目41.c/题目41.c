#include <stdio.h>

void f()
{
	static int m = 0;    //�ùؼ���static����һ����̬ȫ�ֱ���m
	int n = 0;
	printf("��̬ȫ�ֱ�����>%d  ��̬�ֲ�������>%d\n", m, n);
	n++, m++;
}

int main()
{
	f();
	int i = 0;
	for (i = 0; i < 3; i++)    //���3�Σ���̬ȫ�ֱ������䣬��̬�ֲ�����ÿ�������������ͷŵ�
	{
		f();
	}

	return 0;
}
