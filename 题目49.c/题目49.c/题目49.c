#include <stdio.h>

#define Max(a,b) a>b?a:b

int main()
{
#if (1)
	printf("���1\n\n");    //1Ϊ�棬�����һ��printf���
#endif

#if (0)
	printf("���2\n\n");    //0Ϊ�٣�������ڶ���printf���
#endif

#ifdef Max(a,b)    //Max(a,b)�ѱ��궨�壬���������printf��䣬��������ĸ�printf���
	printf("���3\n\n");
#else
	printf("���4\n\n");
#endif

#ifndef Min(a,b)    //Min(a,b)δ���궨�壬����#ifndef��#ifdef��ȡ�������Ա�������printf��䣬�����������printf���
	printf("���5\n\n");
#else
	printf("���6\n\n");
#endif

#define Min(a,b) a<b?a:b    //�궨��Min(a,b)

#ifndef Min(a,b)    //Min(a,b)�ѱ��궨�壬����#ifndef��#ifdef��ȡ�������Ա���ڰ˸�printf��䣬������ھŸ�printf���
	printf("���7\n\n");
#else 
	printf("���8\n\n");
#endif

	return 0;
}