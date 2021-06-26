#include <stdio.h>
#include <stdlib.h>


//暴力循环，超出时间限制
double myPow(double x, int n) {
    if (x == 0 || x == 1) { return x; }

    if (x != 0 && n == 0) { return 1; }

    double res = 0;

    if (n > 0)
    {
        res = x;
        n--;
        while (n)
        {
            res *= x;
            n--;
        }
    }
    else if (n < 0)
    {
        res = 1 / x;
        n++;
        while (n)
        {
            res /= x;
            n++;
        }
    }


    return res;
}

/******************************************************************/
//递归
double myPow(double x, int n) {
    if (n == 0)
        return 1;
    else if (n < 0)
    {
        return 1 / (x * myPow(x, -(n + 1)));
    }
    else
    {
        if (n % 2)
        {
            return x * myPow(x * x, n / 2);
        }
        else
        {
            return myPow(x * x, n / 2);
        }
    }
}

int main()
{
    myPow(2, 10);
	return 0;
}