#include <stdio.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        //memset(matrix[i], 0, sizeof(int) * n);
    }
    //memset(matrix, 0, sizeof(matrix));    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) { matrix[i][j] = 0; }
    }

    int direction[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

    *returnSize = n;

    int i = 0, j = 0;
    int dtmp = 0; //标记当前方向

    for (int k = 0; k < n * n; k++)
    {
        matrix[i][j] = k + 1;

        int nextrow = i + direction[dtmp][0];
        int nextcol = j + direction[dtmp][1];
        if (nextrow < 0 || nextrow >= n || nextcol < 0 || nextcol >= n || matrix[nextrow][nextcol] != 0)
        {
            dtmp = (dtmp + 1) % 4;
        }

        i += direction[dtmp][0];
        j += direction[dtmp][1];
    }

    return matrix;
}


int main()
{

    system("pause");
    return 0;
}