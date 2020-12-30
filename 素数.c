#include <stdio.h>

int main()

{
	int i,m,flag=1;
	printf("请输入一个数值:\n");
	scanf("%d",&m);
	for (i=2;i<=m-1;i++)
		if (m%i==0)
		{
			flag=0;
		}
	if(flag==1)
		printf ("%d是素数\n",m);
	else 
		printf ("%d不是素数\n",m);

	return 0;
}