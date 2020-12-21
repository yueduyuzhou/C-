#include <stdio.h>

int main()
{
	double i,sum;
	printf ("请输入该月所得利润：");
	scanf ("%lf元",&i);
	if (i<=100000)
		sum=i*0.1;
	else if (i<=200000)
		sum=1+(i-10)*0.075;
	else if (i<=400000)
		sum=1+0.75+(i-20)*0.05;
	else if (i<=600000)
		sum=1+0.75+1+(i-40)*0.03;
	else if (i<=1000000)
		sum=1+0.75+1+0.6+(i-60)*0.015;
	else 
		sum=1+0.75+1+0.6+0.6+(i-100)*0.01;
	printf ("应发将金为%.2f元",sum);

	return 0;
}