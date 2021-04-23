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


//���ھ����е� ii �еĵ� jj ��Ԫ�أ�����ת���������ڵ����� ii �еĵ� jj ��λ�á�