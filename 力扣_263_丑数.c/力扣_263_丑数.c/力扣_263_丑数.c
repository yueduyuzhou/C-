#include <stdio.h>
#include <stdlib.h>

bool isUgly(int n) {
    if (n <= 0) { return false; }
    
    while (n)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else if (n % 3 == 0)
        {
            n /= 3;
        }
        else if (n % 5 == 0)
        {
            n /= 5;
        }
        else
        {
            break;
        }
    }

    if (n != 1) { return false; }
    return true;
}