#include <stdio.h>

int main()
{
	int i;
	double total_distance = 0,highly = 100;
	for (i = 0; i < 10; i++)
	{
		total_distance += highly;
		highly = highly / 2;
	}
	printf("共经过%lf米。\n", total_distance);
	printf("第十次反弹高度是%lf米\n", highly);
	return 0;
}
