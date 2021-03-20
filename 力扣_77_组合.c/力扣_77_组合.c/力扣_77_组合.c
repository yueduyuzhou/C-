#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************************************************************/
//评论解，可参考
//方法一：回溯法
//1,结束条件，排列了K个数
//2,回溯处理：下层节点只能使用上层节点未使用过的整数

//优化一：回溯处理循环时减少循环次数(n - k + index + 1)

//函数一：求组合的数量
int getMaxComBineNum(int n, int k) {
    int         iRet = 0;
    int         i = 0;
    long int    iTmp1 = 1;
    long int    iTmp2 = 1;

    for (i = 0; i < k; i++)
    {
        iTmp1 *= n - i;
        iTmp2 *= i + 1;
    }
    iRet = iTmp1 / iTmp2 + 1;
    return iRet;
}

//函数二：回溯函数
//1,val传入上一层的代入值，下一层只用后面的数字
//2,index 作为回溯函数下标，控制回溯层数
void backTrackCombine(int** pRet, int n, int k, int* pColSize, int* pRetNum, int val, int index) {
    int     i = 0;
    int     j = 0;
    if (NULL == pRet[*pRetNum])
    {
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (k + 1));
        memset(pRet[*pRetNum], 0x00, sizeof(int) * (k + 1));
    }

    //1,结束条件
    if (index == k)
    {
        pColSize[*pRetNum] = k;
        *pRetNum += 1;
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (k + 1));
        memcpy(pRet[*pRetNum], pRet[(*pRetNum) - 1], sizeof(int) * (k + 1));
        return;
    }

    //2,回溯处理
    for (i = val + 1; i <= (n - k + index + 1); i++)
    {
        pRet[*pRetNum][index] = i;
        backTrackCombine(pRet, n, k, pColSize, pRetNum, i, index + 1);
    }

    return;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int** pRet = NULL;
    int* pColSize = NULL;
    int         iMax = 0;
    int         iRetNum = 0;

    //1,计算组合数量，并初始化指针
    iMax = getMaxComBineNum(n, k);

    pRet = (int**)malloc(sizeof(int*) * iMax);
    memset(pRet, 0x00, sizeof(int*) * iMax);
    pColSize = (int*)malloc(sizeof(int) * iMax);
    memset(pColSize, 0x00, sizeof(int) * iMax);

    //2,回溯处理
    backTrackCombine(pRet, n, k, pColSize, &iRetNum, 0, 0);

    //3,返回
    *returnSize = iRetNum;
    *returnColumnSizes = pColSize;
    return pRet;
}
/****************************************************************************************************************************************/
//算出组合数量
int getMaxCombineNum(int n, int k)
{
    int i = 0;
    //int tmpn = 1;
    long int tmpk = 1;
    long int tmpnk = 1;
    //while (i <= n)
    //{
    //    tmpn *= k + i;
    //    if (i <= k) {tmpk *= i;}
    //    if (i <= n - k) {tmpnk *= i;}
    //    i++;
    //}
    //return tmpn / (tmpk * tmpnk);
    while (i < k)
    {
        tmpk *= i + 1;    //算出k!
        tmpnk *= n - i;
        i++;
    }
    return tmpnk / tmpk + 1;
}

/*int getMaxCombineNum(int n, int k){
    int         iRet        = 0;
    int         i           = 0;
    long int    iTmp1       = 1;
    long int    iTmp2       = 1;

    for (i = 0; i < k; i++)
    {
        iTmp1 *= n - i;
        iTmp2 *= i + 1;    //算出k!
    }
    iRet = iTmp1 / iTmp2 + 1;
    return iRet;
}*/

void backTrackCombine(int** res, int n, int k, int* resSize, int* colSize, int val, int index)
{
    if (res[*resSize] == NULL)
    {
        res[*resSize] = (int*)malloc(sizeof(int) * (k + 1));
        memset(res[*resSize], 0X00, sizeof(int) * (k + 1));
    }

    //退出条件
    if (index == k)
    {
        colSize[*resSize] = k;
        (*resSize)++;
        res[*resSize] = (int*)malloc(sizeof(int) * (k + 1));
        memcpy(res[*resSize], res[(*resSize) - 1], sizeof(int) * (k + 1));
        return;
    }

    for (int i = val + 1; i <= (n - k + index + 1); i++)
    {
        res[*resSize][index] = i;
        backTrackCombine(res, n, k, resSize, colSize, i, index + 1);
    }

    return;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int** res = NULL;
    int* colSize = NULL;
    int     iMax = 0;
    int     resSize = 0;

    //计算组合的数量
    iMax = getMaxCombineNum(n, k);

    res = (int**)malloc(sizeof(int*) * iMax);
    memset(res, 0X00, sizeof(int*) * iMax);
    colSize = (int*)malloc(sizeof(int) * iMax);
    memset(colSize, 0X00, sizeof(int) * iMax);

    //进入回溯
    backTrackCombine(res, n, k, &resSize, colSize, 0, 0);

    *returnSize = resSize;
    *returnColumnSizes = colSize;

    return res;
}

int main()
{

	system("pause");

	return 0;
}