#include <stdio.h>
#include <assert.h>
#include <malloc.h>

double* subroutine(int n)
{
	if (n % 2 == 0){//nΪż��
		double* num = (double*)malloc(sizeof(double));
		assert(num);
		*num = 0;
		for (double i = 2; i <= n; i += 2)
			*num = *num + (1 / i);
		return num;
	}
	else{//nΪ����
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
	printf("����һ������:>");
	scanf("%d", &n);
	double* num = subroutine(n);
	printf("\n���Ϊ:>%lf", *num);

	return 0;
}