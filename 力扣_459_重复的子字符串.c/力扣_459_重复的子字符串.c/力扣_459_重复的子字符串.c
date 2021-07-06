#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    int i = 1;
    while (i <= n / 2)
    {
        if (n % i == 0) {
            bool match = true;
            int j = i;
            while (j < n)
            {
                if (s[j] != s[j - i]) {
                    match = false;
                    break;
                }
                j++;
            }
            if (match) {
                return true;
            }
        }
        i++;
    }
    return false;
}


int main()
{

    system("pause");
    return 0;
}