#include <stdio.h>

int main()

{
	int i;
	label:printf("***********\n");
	for (i=1;i<=10;i++)
	{
		
		goto label;
	}
	return 0;
}