#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    if (n == 1) { return true; }

    while (n && n % 4 == 0)
    {
        n /= 4;
    }

    if (n == 1) { return true; }
    else { return false; }
}


int main()
{

    return 0;
}