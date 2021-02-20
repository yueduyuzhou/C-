#include <stdio.h>

int main()
{
	int num = 0;
	int tmp = 0;
	int arr[5] = { 0 };
	scanf("%d", &num);

	while (num)
	{
		arr[tmp++] = (num % 10 + 5) % 10;
		num /= 10;
	}

	for (int i = 0;i < tmp;i++)
		printf("%d", arr[i]);

	return 0;
}