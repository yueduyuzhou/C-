#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//分配整个杨辉三角的内存，计算出所有行
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int** res = (int**)malloc(sizeof(int*) * (rowIndex + 1));
    assert(res);

    for (int i = 0; i <= rowIndex; i++)
    {
        res[i] = (int*)malloc(sizeof(int*) * (i + 1));
        assert(res[i]);
        res[i][0] = res[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }

    return res[rowIndex];
}
/************************************************************************************************/
//优化1
//采用滚动数组，节省空间
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    //开辟两个数组轮换为上一行
    int* cur = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(cur);
    memset(cur, 0, sizeof(int) * (rowIndex));
    int* pre = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(pre);
    memset(pre, 0, sizeof(int) * (rowIndex));

    for (int i = 0; i <= rowIndex; i++)
    {
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i; j++)
        {
            cur[j] = pre[j - 1] + pre[j];
        }
        //轮换
        int* tmp = cur;
        cur = pre;
        pre = tmp;
    }

    return pre;
}
/*************************************************************************************************/
//优化2
//使用一个数组，第j元素都属上一行的j-1和j的和，计算使从后算起
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int* res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(res);
    memset(res, 0, sizeof(int) * (rowIndex + 1));

    res[0] = 1;
    for (int i = 1; i <= rowIndex; i++)
    {
        for (int j = i; j > 0; j--)
        {
            res[j] += res[j - 1];
        }
    }

    return res;
}
/************************************************************************************************/
//优化3
//公式运用，直接算出结果行的每一个元素
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int* res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(res);
    res[0] = 1;

    for (int i = 1; i <= rowIndex; i++)
    {
        res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
    }

    return res;
}

int main()
{

	system("pause");

	return 0;
}