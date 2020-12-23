#include <stdio.h>

int main ()
{
	int a,c,z,i;
	int arr[100];
	scanf ("%d",&z);
	printf ("%d=",z);
	a = 0;
	for (c = 2;z != 1;)	//判断所有是否因数已找到
	{
		if (z%c == 0)  //判断能否整除
		{
			z = z/c;
			arr[a] = c;  //储存因数
			a++;  //计算因数个数
			c = 2;
			//for (d = 0;d < 100;d++)
			//{
				//arr[d] = c;
				//c = 2;
				//break;
			//}
		}
		else
		{
			c++;
		}
	}
	
	printf ("%d",arr[0]);
	for (i = 1;i < a;i++)
	{
		printf ("*%d",arr[i]);
	}
	printf ("\n");
	main ();  //一次运行中计算多次
	return 0;
}
