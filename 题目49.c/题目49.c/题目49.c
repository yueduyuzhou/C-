#include <stdio.h>

#define Max(a,b) a>b?a:b

int main()
{
#if (1)
	printf("语句1\n\n");    //1为真，编译第一个printf语句
#endif

#if (0)
	printf("语句2\n\n");    //0为假，不编译第二个printf语句
#endif

#ifdef Max(a,b)    //Max(a,b)已被宏定义，编译第三个printf语句，不编译第四个printf语句
	printf("语句3\n\n");
#else
	printf("语句4\n\n");
#endif

#ifndef Min(a,b)    //Min(a,b)未被宏定义，由于#ifndef是#ifdef的取反，所以编译第五个printf语句，不编译第六个printf语句
	printf("语句5\n\n");
#else
	printf("语句6\n\n");
#endif

#define Min(a,b) a<b?a:b    //宏定义Min(a,b)

#ifndef Min(a,b)    //Min(a,b)已被宏定义，由于#ifndef是#ifdef的取反，所以编译第八个printf语句，不编译第九个printf语句
	printf("语句7\n\n");
#else 
	printf("语句8\n\n");
#endif

	return 0;
}