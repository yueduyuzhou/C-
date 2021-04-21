void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int tmp = *matrixColSize;
    int tag[matrixSize][tmp];
    memset(tag, 0, sizeof(tag));

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (matrix[i][j] == 0)
            {
                tag[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (tag[i][j] == 1)
            {
                for (int i2 = 0; i2 < matrixSize; i2++)
                {
                    matrix[i2][j] = 0;
                }
                for (int j2 = 0; j2 < *matrixColSize; j2++)
                {
                    matrix[i][j2] = 0;
                }
            }
        }
    }

}