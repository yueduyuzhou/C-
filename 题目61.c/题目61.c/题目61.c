#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	int arr[10][10] = { 0 };
	//printf("1\n");
	arr[0][0] = 1;
	printf("%d\n", arr[0][0]);
	for (i = 1; i < 10; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
		printf("%d\t", arr[i][0]);
		//printf("1\t");
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			printf("%d\t", arr[i][j]);
		}
		printf("%d", arr[i][i]);
		printf("\n");
	}

		return 0;
}