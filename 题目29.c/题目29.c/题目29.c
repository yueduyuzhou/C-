#include <stdio.h>

void Contrary(int i)
{
	int arr[5], m = 0;
	for (m = 0; m < 5; m++)
	{
		arr[m] = i % 10;   //从数的末位开始按位赋给数组
		i = i / 10;
	}
//	int left = 0;
//	while (left != right)    //由于上面摩10后的数从头开始赋给arr数组，所以无需再排列
//	{
//		int a = 0;
//		a = arr[left];
//		arr[left] = arr[right];
//		arr[right] = a;
//		left++;
//		right--;
//	}
	printf("他的逆序是");
	for (m = 0; m < 5; m++)   //从arr[0]开始打印
	{
		printf("%d", arr[m]);
	}
}

int main()
{
	int i = 0, n = 0, k = 0;
	scanf_s("%d", &i);
	k = i;
	while (i > 0)
	{
		i = i / 10;
		n++;
	}
	printf("这个数值是%d位数\n", n);
	Contrary(k);
}