#include <stdio.h>

int main()
{
	int a = 1;
	int n = 0;
	int num = 0;
	printf("����һ���˽�����:>");
	scanf("%d", &num);
	//�˽���תʮ���ƣ����˽�������Ȩչ��(ʮ�����ƣ���������ͬ)
	//�˽�����226 == ʮ������2 * 8�Ķ��η� + 2 * 8��һ�η� + 6 * 8����η�
	while (num != 0)
	{
		n += num % 10 * a;
		a *= 8, num /= 10;
	}
	printf("%d", n);

	return 0;
}