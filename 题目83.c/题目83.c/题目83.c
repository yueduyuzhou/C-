#include <stdio.h>

//����Ŀû��˵������λ�������ֲ����ظ�����
int main()
{
	unsigned int n = 0;
	unsigned int m = 0;
	unsigned int sum = 0;
	for (n = 1; n < 9; n++)
	{
		if (n == 1)
			m = 4;
		else if (n == 2)
			m = 4 * 7;
		else
			m *= 8;
		printf("%dλ����%d���������;\n\n", n, m);
		sum += m;
	}
	printf("1��8λ����%d���������\n", sum);
	return 0;
}