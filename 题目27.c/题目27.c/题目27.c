#include <stdio.h>

void Trans(char arr[],int left,int right)
{
	char a;
	a = arr[right];
	arr[right] = arr[left];
	arr[left] = a;
	left++, right--;
	if (left != right)
	{
		Trans(arr, left, right);
	}
	if (left != right)
	{
		printf("%s\n", arr);
	}
}

void main()
{
	char arr[6];
	scanf_s("%s", arr, 6);
//	int sz = (sizeof(arr) / sizeof(arr[0]));
	int left = 0, right = 4;
	Trans(arr, left, right);
}