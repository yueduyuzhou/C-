#include <stdio.h>
#include <math.h>

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    int base = minutesToTest / minutesToDie + 1;  //每只猪最多可以测的次数
    while (pow(base, pigs) < buckets)
    {
        pigs++;
    }

    return pigs;
}

int main()
{
	return 0;
}