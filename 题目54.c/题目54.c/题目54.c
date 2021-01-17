#include <stdio.h>

//int main()
//{
//	printf("输入一个整数:>");
//	long long int a = 0;
//	scanf("%lld", &a);
//
//	a /= 1000;
//	int arr[4] = { 0 };
//	printf("\n倒数第4到第7是:>");
//
//	for (int i = 0; i < 4; i++)
//	{
//		arr[i] = a % 10;
//		a /= 10;
//		printf("%d\t", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


int main()
{
	int a = 0;        
	scanf("%d", &a);   //1001 1010 0101-----2469

	a = a >> 4;        //0000 1001 1010-----右移四位
					   //0000 0000 1111-----15
	a = a & 15;		   //0000 0000 1010
	printf("%d", a);   

	return 0;
}

