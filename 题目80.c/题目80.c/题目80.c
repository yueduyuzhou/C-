#include <stdio.h>

int main()
{
	int x = 0, y = 1;
	int i = 0;

	while (i < 5)
	{
		x = y * 4;
		for (i = 0; i < 5; i++)
		{

			if (x % 4 != 0)
				break;
			x = x / 4 * 5 + 1;

		}
		y++;
	}
	printf("%d\n", x);
	return 0;
}