#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char** fizzBuzz(int n, int* returnSize) {
    int i = 1;
    char** res = (char**)malloc(sizeof(char*) * n);
    assert(res);
    char* fizz = malloc(5);
    char* buzz = malloc(5);
    char* fb = malloc(9);
    sprintf(fizz, "%s", "Fizz");
    sprintf(buzz, "%s", "Buzz");
    sprintf(fb, "%s", "FizzBuzz");


    while (i <= n)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            res[i - 1] = fb;
        }
        else if (i % 3 == 0)
        {
            res[i - 1] = fizz;
        }
        else if (i % 5 == 0)
        {
            res[i - 1] = buzz;
        }
        else
        {
            res[i - 1] = malloc(10);
            sprintf(res[i - 1], "%d", i);
        }
        i++;
    }

    *returnSize = n;
    return res;
}


int main()
{

    system("pause");
    return 0;
}