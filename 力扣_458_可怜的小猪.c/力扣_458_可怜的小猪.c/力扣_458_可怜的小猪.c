#include <stdio.h>
#include <math.h>

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    int base = minutesToTest / minutesToDie + 1;  //ÿֻ�������Բ�Ĵ���
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