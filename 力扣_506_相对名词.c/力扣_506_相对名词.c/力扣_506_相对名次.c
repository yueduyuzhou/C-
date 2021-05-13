#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//typedef struct _Data{
//int index;
//int val;
//} Data;
//
//int cmp(const void* a, const void* b) {
//    return ((Data*)b)->val - ((Data*)a)->val;
//}
//
//char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
//    *returnSize = numsSize;
//    if (numsSize == 0) return NULL;
//    Data* d = (Data*)malloc(numsSize * sizeof(Data));
//    int i;
//    for (i = 0; i < numsSize; ++i) {
//        d[i].index = i;
//        d[i].val = nums[i];
//    }
//    qsort(d, numsSize, sizeof(Data), cmp);
//    char** res = (char**)malloc(numsSize * sizeof(char*));
//    memset(res, 0, numsSize * sizeof(char*));
//    for (i = 0; i < numsSize; ++i) {
//        res[d[i].index] = (char*)malloc(13 * sizeof(char));
//        memset(res[d[i].index], 0, 13 * sizeof(char));
//        switch (i) {
//        case 0:
//            sprintf(res[d[i].index], "Gold Medal");
//            break;
//        case 1:
//            sprintf(res[d[i].index], "Silver Medal");
//            break;
//        case 2:
//            sprintf(res[d[i].index], "Bronze Medal");
//            break;
//        default:
//            sprintf(res[d[i].index], "%d", i + 1);
//            break;
//        }
//    }
//    return res;
//}

/**************************************************************************************************************************************/

int FindMax(int* a, int size)
{
    int i = 0, j = 0;
    int maxnum = -1;
    //查找当前数组的最大值
    while (i < size)
    {
        if (maxnum < a[i])
        {
            j = i;
            maxnum = a[i];
        }
        i++;
    }
    //把找到的位置置为-1
    a[j] = -1;
    return j;
}


char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * scoreSize);
    assert(res);

    char* gm = malloc(13);
    char* sm = malloc(13);
    char* bm = malloc(13);
    sprintf(gm, "%s", "Gold Medal");
    sprintf(sm, "%s", "Silver Medal");
    sprintf(bm, "%s", "Bronze Medal");

    int max = FindMax(score, scoreSize);
    int mid = FindMax(score, scoreSize);
    int min = FindMax(score, scoreSize);
    if (scoreSize == 1) { res[max] = gm; }
    else if (scoreSize == 2)
    {
        res[max] = gm;
        res[mid] = sm;
    }
    else
    {
        res[max] = gm;
        res[mid] = sm;
        res[min] = bm;
    }


    int i = 3;
    while (i < scoreSize)
    {
        int temp = FindMax(score, scoreSize);
        res[temp] = malloc(6);
        sprintf(res[temp], "%d", i + 1);

        i++;
    }

    *returnSize = scoreSize;
    return res;
}
/**************************************************************************************************************************************/

int main()
{
    int a[] = { 5 };
    int s = 0;
    findRelativeRanks(a, 1, &s);

    system("pause");
    return 0;
}