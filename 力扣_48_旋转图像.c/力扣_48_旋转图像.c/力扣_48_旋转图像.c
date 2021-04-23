void rotate(int** matrix, int matrixSize, int* matrixColSize) {


    int** res = (int**)malloc(sizeof(int*) * matrixSize);
    assert(res);
    for (int i = 0; i < matrixSize; i++)
    {
        res[i] = (int*)malloc(sizeof(int) * matrixSize);
        assert(res);
    }

    int i2 = 0;
    int j2 = matrixSize - 1;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            printf("%d%d ", i2, j2);
            res[i2++][j2] = matrix[i][j];
            if (i2 == matrixSize)
            {
                j2--;
                i2 = 0;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = res[i][j];
        }
        free(res[i]);
        res[i] = NULL;
    }

    free(res);
    res = NULL;
}


//对于矩阵中第 ii 行的第 jj 个元素，在旋转后，它出现在倒数第 ii 列的第 jj 个位置。