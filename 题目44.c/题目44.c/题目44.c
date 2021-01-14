#include <stdio.h>

//int main()
//{
//	extern a ;    //变量a定义在使用后，前面要加extern
//	printf("%d", a);    //
//
//	return 0;
//}
//int a = 123;    //定义a

int main()
{
	extern a;
	for (a = 1; a < 100; a++)
	{
		printf("%d\t", a);
	}
	printf("\n\n\n");

	extern s;
	for (; s < 123; s++)
	{
		printf("%c\t", s);
	}

	return 0;
}

int a = 0;
char s = 65;