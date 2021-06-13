#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    //if (x > 2147483647 || x < -2147483648) {return 0;}

    //int poandne = 0;
    //if (x > 0) {poandne = 1;}
    //if (x < 0) {poandne = -1; x *= -1;}

    int num = 0;
    while (x)
    {
        if (num > 214748364 || num < -214748364) { return 0; }

        num = num * 10 + x % 10;
        x /= 10;
    }

    return num; //* poandne;
}

int main()
{
    reverse(123);
	exit(0);
}