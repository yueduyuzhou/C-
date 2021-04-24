/**************************************************************************************************************************/
//暴力计算出每一个结果，重复计算次数太多
//时间复杂度太高，力扣超出时间限制
typedef struct {
    int** nums;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* res = malloc(sizeof(NumMatrix));
    assert(res);
    res->nums = malloc(sizeof(int*) * matrixSize);
    assert(res->nums);
    for (int i = 0; i < matrixSize; i++)
    {
        res->nums[i] = malloc(sizeof(int) * *matrixColSize);
        assert(res->nums[i]);
    }

    //待改进
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            res->nums[i][j] = matrix[i][j];
        }
    }

    return res;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    //待改进
    int sum = 0;
    for (int i = row1; i <= row2; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            sum += obj->nums[i][j];
        }
    }

    return sum;
}

void numMatrixFree(NumMatrix* obj) {
    free(obj->nums);
    obj->nums = NULL;
    free(obj);
    obj = NULL;
}
/**************************************************************************************************************************/
//改进1
//在自定义的二维矩阵中直接计算出每一个点到[0][0]的所有节点的和
//由公式：res->nums[i][j] = res->nums[i - 1][j] + res->nums[i][j - 1] - res->nums[i - 1][j - 1] + matrix[i - 1][j - 1];

typedef struct {
    int** nums;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* res = (NumMatrix*)malloc(sizeof(NumMatrix));
    assert(res);
    res->nums = (int**)malloc(sizeof(int*) * (matrixSize + 1));
    assert(res->nums);
    for (int i = 0; i <= matrixSize; i++)
    {
        res->nums[i] = (int*)malloc(sizeof(int) * (*matrixColSize + 1));
        assert(res->nums[i]);
    }
    
    //初始化最上面一行和最左边一列为0
    for (int i = 0; i <= matrixSize; i++)
    {
        res->nums[i][0] = 0;
    }
    for (int j = 1; j <= *matrixColSize; j++)
    {
        res->nums[0][j] = 0;
    }

    //printf("%d %d",matrixSize,*matrixColSize);

    //根据已初始化部分，遍历剩下
    for (int i = 1; i <= matrixSize; i++)
    {
        for (int j = 1; j <= *matrixColSize; j++)
        {
            res->nums[i][j] = res->nums[i - 1][j] + res->nums[i][j - 1] - res->nums[i - 1][j - 1] + matrix[i - 1][j - 1];

            //printf("%d", res->nums[i][j]);    
        }
    }

    return res;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    return obj->nums[row2 + 1][col2 + 1] - obj->nums[row1][col2 + 1] - obj->nums[row2 + 1][col1] + obj->nums[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {
    free(obj->nums);
    obj->nums = NULL;
    free(obj);
    obj = NULL;
}
