#include <stdio.h>
#include <assert.h>
#include <malloc.h>

double* subroutine(int n)
{
	if (n % 2 == 0){//n为偶数
		double* num = (double*)malloc(sizeof(double));
		assert(num);
		*num = 0;
		for (double i = 2; i <= n; i += 2)
			*num = *num + (1 / i);
		return num;
	}
	else{//n为奇数
		double* num = (double*)malloc(sizeof(double));
		assert(num);
		*num = 0;
		for (double i = 1; i <= n; i += 2)
			*num = *num + (1 / i);
		return num;
	}
}



int main()
{
	int n = 0;
	printf("输入一个整数:>");
	scanf("%d", &n);
	double* num = subroutine(n);
	printf("\n结果为:>%lf", *num);

	return 0;
}