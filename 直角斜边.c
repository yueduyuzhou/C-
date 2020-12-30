#include <math.h>

int main()
{
	float a,b,c;

	printf("请输入两直角边长：\n");
	scanf("%f%f",&a,&b);

	c=sqrt(a*a+b*b);

	printf("斜边长为:%f\n",c);
	
	return 0;
}