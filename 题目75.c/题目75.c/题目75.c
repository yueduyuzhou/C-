#include <stdio.h>
#include <math.h>
//����mathͷ�ļ���ʹ��pow()������pow(x,y)��ʾx��y�η�

int main()
{
	int num = 0;
	int i = 0, j = 0;
	int arr[10] = { 0 };
	scanf("%d", &num);
	while (num != 0)
	{
		arr[i++] = num % 10;
		num /= 10;
	}
	while (j != 6)
	{
		num = num + arr[--i] * (int)pow(10, j++);
	}
	printf("%d", num);
	return 0;
}