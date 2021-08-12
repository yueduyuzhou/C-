#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    if (n == 1) { return true; }

    while (n && n % 3 == 0)
    {
        n /= 3;
    }

    if (n == 1) { return true; }
    else { return false; }
}

int main()
{
    return 0;
}