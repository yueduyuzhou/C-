#include <stdio.h>

int main()
{
    int num = 0;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &num);
        while (num > 0)
        {
            printf("*");
            num--;
        }
        printf("\n");
    }
    return 0;
}