/*****************************************************************************************************************************/
//有bug

int ToIntMin(char* time)
{
    int res = 0;
    int mingap = (time[3] - '0') * 10 + (time[4] - '0');
    int hougap = (time[0] - '0') * 10 + (time[1] - '0');
    //printf ("%d %d", mingap, hougap);
    res = hougap * 60 + mingap;

    return res;
}

bool mycom(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findMinDifference(char** timePoints, int timePointsSize) {

    //设置一个int数组
    int* timenum = (int*)malloc(sizeof(int) * timePointsSize);
    assert(timenum);

    //printf ("%d", timePointsSize);

    //存放timePoints转化为整数的结果 (时间是00:00转化为12:00,即1440分钟)
    int i = 0;
    while (i < timePointsSize)
    {
        timenum[i] = ToIntMin(timePoints[i]);
        if (timenum[i] == 0)
        {
            timenum[i] = 1440;
        }
        printf("%d ", timenum[i]);
        i++;
    }


    //两层遍历计算所有的差，迭代记录最小的差
    i = 0;
    int j = 0, min = 1440;
    while (i < timePointsSize)
    {
        j = 0;
        while (j < timePointsSize)
        {
            int gap = timenum[i] - timenum[j];

            if (i != j && gap >= 0 && gap < min)
            {
                min = gap;
                //printf ("%d   ", min);
            }

            j++;
        }

        i++;
    }

    //ToIntMin(timePoints[1]);

    return min;
}

/*****************************************************************************************************************************/
int ToIntMin(char* time)
{
    int res = 0;
    int mingap = (time[3] - '0') * 10 + (time[4] - '0');
    int hougap = (time[0] - '0') * 10 + (time[1] - '0');
    //printf ("%d %d", mingap, hougap);
    res = hougap * 60 + mingap;

    return res;
}

int mycom(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)b);
}

int findMinDifference(char** timePoints, int timePointsSize) {

    //设置一个int数组
    int* timenum = (int*)malloc(sizeof(int) * timePointsSize);
    assert(timenum);

    //printf ("%d", timePointsSize);

    //存放timePoints转化为整数的结果 (时间是00:00转化为12:00,即1440分钟)
    int i = 0;
    while (i < timePointsSize)
    {
        timenum[i] = ToIntMin(timePoints[i]);
        if (timenum[i] == 0)
        {
            timenum[i] = 1440;
        }
        //printf ("%d ", timenum[i]);
        i++;
    }

    //排序
    qsort(timenum, timePointsSize, sizeof(int), mycom);

    //两层遍历计算所有的差，迭代记录最小的差
    i = 0;
    int j = 0, min = 1440;
    for (int i = 0; i < timePointsSize - 1; i++) {
        int tmp = timenum[i + 1] - timenum[i];
        if (tmp == 0) return 0;  //没有比0更小的间隔了
        if (tmp < min) min = tmp;
    }

    //ToIntMin(timePoints[1]);

    return 1440 - timenum[timePointsSize - 1] + timenum[0] < min ? 1440 - timenum[timePointsSize - 1] + timenum[0] : min;
}

/*****************************************************************************************************************************/


#define DAY_MINU (24*60)
int  compare(const void* a, const void* b) {
    return (*((int*)a) - *((int*)b));
}
int findMinDifference(char** timePoints, int timePointsSize) {
    int minu_array[timePointsSize], hour, minu;
    for (int i = 0; i < timePointsSize; ++i) {
        sscanf(timePoints[i], "%d:%d", &hour, &minu);
        minu_array[i] = hour * 60 + minu;
    }
    qsort(minu_array, timePointsSize, sizeof(int), compare);

    int min_point = 0x7fffffff;
    for (int i = 0; i < timePointsSize - 1; ++i) {
        int tmp = minu_array[i + 1] - minu_array[i];
        if (tmp == 0) return 0;  //没有比0更小的间隔了
        if (tmp < min_point) min_point = tmp;
    }

    return (DAY_MINU - minu_array[timePointsSize - 1] + minu_array[0]) < min_point ?
        (DAY_MINU - minu_array[timePointsSize - 1] + minu_array[0]) :
        min_point;
}