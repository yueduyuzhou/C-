#include <stdio.h>

//时间复杂度O(n*n)
//空间复杂度O(1);
//暴力破解
int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 1 && citations[0] == 0) { return 0; }

    int num = 0;
    //int count = 0;
    int h = 0;
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < citationsSize; i++)
        {
            if (citations[i] > h) { num++; }
            //printf ("%d ",num);
            if (num > h)
            {
                flag = 1;
                h++;
                break;
            }
            printf("%d ", h);
        }
        if (flag == 0) { break; }
        num = 0;
    }

    return h;
}
/************************************************************************************/
//时间复杂度O(n)
//空间复杂度O(1)
//先排序在遍历
int cmp(const void* a, const void* b)
{
    return (*(int*)b) - (*(int*)a);
}

int hIndex(int* citations, int citationsSize) {
    //从大到小排序
    qsort(citations, citationsSize, sizeof(int), cmp);

    int h = 0;
    while (h < citationsSize && citations[h] > 0)
    {
        if (citations[h] > h) { h++; }
        else { break; }
    }

    return h;
}
int main()
{

	return 0;
}