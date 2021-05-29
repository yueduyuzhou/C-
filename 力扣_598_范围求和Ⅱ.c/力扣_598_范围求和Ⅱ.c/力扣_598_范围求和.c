#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*********************************************************************************************************************/
//时间复杂度太高，力扣超出时间限制
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int** res = (int**)malloc(sizeof(int*) * m);
    assert(res);
    for (int i = 0; i < m; i++)
    {
        res[i] = (int*)calloc(n, sizeof(int));
        assert(res[i]);
        //memset(res, 0, sizeof(int) * n);
    }

    //int tmp = 4;
    for (int tmp = 0; tmp < opsSize; tmp++)
    {
        //printf ("%d ", tmp);
        for (int i = 0; i < ops[tmp][0]; i++)
        {
            for (int j = 0; j < ops[tmp][1]; j++)
            {
                res[i][j]++;
            }
        }
    }
    //printf ("%d ", opsSize);
    //printf ("%d ", *opsColSize);
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[i][j] == res[0][0]) { ret++; }
        }
    }

    free(res);
    res = NULL;

    return ret;
}
/*********************************************************************************************************************/
//改进
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    if (opsSize == 0) { return m * n; }

    int mini = 40000;
    int minj = 40000;

    for (int i = 0; i < opsSize; i++)
    {
        mini = mini < ops[i][0] ? mini : ops[i][0];
        minj = minj < ops[i][1] ? minj : ops[i][1];
    }

    return mini * minj;
}

int main()
{
    int a = maxCount(40000, 40000, NULL, 0, 0);


    //system("pause");

	return 0;
}