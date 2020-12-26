#include <stdio.h>

void Number_of_peach(int a,int count)
{

	if (count < 10)
	{
		a = (a + 1) * 2;
		count++;
		Number_of_peach(a, count);
	}
	printf("%d\n", a);
}

int main()
{
	int a = 1;
	int count = 1;
	Number_of_peach(a,count);

	return 0;
}