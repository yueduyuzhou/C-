#include <stdio.h>

//void main()
//{
//	int i = 0, n = 0, m = 0, h = 0;
//
//	char team1[3] = { 'x','y','z' };
//	char team2[3] = { 'a','b','c' };
//
//	for (i = 0; i < 3; i++)
//	{
//		if (team2[i] == 'c')
//		{
//			for (n = 0; n < 3; n++)
//			{
//				if (team1[n] == 'x' || team1[n] == 'z')
//				{
//					continue;
//				}
//				else
//				{
//					printf("c VS %c\n", team1[n]);
//					m = n;
//					break;
//				}
//			}
//			
//		}
//		if (team2[i] == 'a')
//		{
//			for (n = 0; n < 3; n++)
//			{
//				if (team1[n] == 'x' || n == m)
//				{
//					continue;
//				}
//				else
//				{
//					printf("a VS %c\n", team1[n]);
//					h = n;
//					break;
//				}
//			}
//		}
//		for (n = 0; n < 3; n++)
//		{
//			if (n != m || n != h)
//			{
//				printf("b VS %c\n", team1[n]);
//				break;
//			}
//		}
//		
//	}
//}


void main()
{
	char a, b, c;

	for (a = 'x'; a >= 'x' && a <= 'z'; a++)
	{
		for (b = 'x'; b >= 'x' && b <= 'z'; b++)
		{
			for (c = 'x'; c >= 'x' && c <= 'z'; c++)
			{
				if (a != 'x' && c != 'x' && c != 'z' && a != b && b != c && a != c)
				{
					printf("a VS %c\n", a);
					printf("b VS %c\n", b);
					printf("c VS %c\n", c);
				}
			}
		}
	}
}