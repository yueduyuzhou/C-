#include <stdio.h>
#include <stdlib.h>

char* ToBinary(char arr[], int num)
{
	itoa(num, arr, 2);
	return arr;
}

int main()
{
	int a = 0, b = 0, i = 0;
	char arr[33] = { 0 };
	scanf("%d%d", &a, &b);
	printf("a = %s\n", ToBinary(arr, a));
	printf("b = %s\n", ToBinary(arr, b));
	i = a & b;
	printf("i(&) = %s\n", ToBinary(arr, i));

	i = a | b;
	printf("i(|) = %s\n", ToBinary(arr, i));

	i = a ^ b;
	printf("i(^) = %s\n", ToBinary(arr, i));

	i = ~a;
	printf("a(~) = %s\n", ToBinary(arr, i));
	i = ~b;
	printf("b(~) = %s\n", ToBinary(arr, i));

	return 0;
}