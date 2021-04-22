#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * numRows);
    assert(res);
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    assert(*returnColumnSizes);

    //初始化并使每一行的首尾为1
    for (int i = 0; i < numRows; i++)
    {
        res[i] = (int*)malloc(sizeof(int) * (i + 1));
        assert(res[i]);

        (*returnColumnSizes)[i] = i + 1;

        res[i][0] = 1;
        if (i != 0) { res[i][i] = 1; }
    }

    //填充剩余部分
    for (int i = 2; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }

    *returnSize = numRows;
    return res;
}

/****************************************************************************************************************/
//官方解
/*int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i) {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}*/


int main()
{

	system("pause");
	
}