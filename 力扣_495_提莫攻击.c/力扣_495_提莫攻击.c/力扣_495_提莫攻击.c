#include <stdio.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0) { return 0; }

    int total = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++)
    {
        if (timeSeries[i + 1] - timeSeries[i] >= duration) { total += duration; }
        else { total += timeSeries[i + 1] - timeSeries[i]; }
    }

    return total + duration;
}

int main()
{
    int a[2] = { 1,4 };
    findPoisonedDuration(a, 2, 2);
	return 0;
}