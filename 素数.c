#include <stdio.h>

int main()

{
	int i,m,flag=1;
	printf("������һ����ֵ:\n");
	scanf("%d",&m);
	for (i=2;i<=m-1;i++)
		if (m%i==0)
		{
			flag=0;
		}
	if(flag==1)
		printf ("%d������\n",m);
	else 
		printf ("%d��������\n",m);

	return 0;
}