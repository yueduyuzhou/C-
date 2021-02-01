#include <stdio.h>

#define N 4

struct man
{
	char name[20];
	int age;
};

person[N] = { "zhaomyun",18,"ui",22,"guangyu",20,"xiaoyushen",21 };

int main()
{
	int i = 0;
	struct man* a, * b;
	a = person;
	for (i = 0; i < N; i++)
	{
		int max = 0;
		if (max < a->age)
		{
			b = a++;
			max = b->age;
		}
	}
	printf("%s\n%d\n", b->name, b->age);
	return 0;
}