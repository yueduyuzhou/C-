#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n == 1) { return true; }

    while (n && n % 2 == 0)
    {
        n /= 2;
    }

    if (n == 1) { return true; }
    else { return false; }
}

int main()
{
    return 0;
}