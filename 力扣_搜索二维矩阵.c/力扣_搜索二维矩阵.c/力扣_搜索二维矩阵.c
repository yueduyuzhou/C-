#include <stdio.h>
#include <assert.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //matrixSize:矩阵行数
    //matrixColSize:矩阵列数
    int x = 0, y = 0;
    int* tmparr = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    assert(tmparr);

    for (x = 0; x < matrixSize; x++)
    {
        for (y = 0; y < *matrixColSize; y++)
        {
            tmparr[x * (*matrixColSize) + y] = matrix[x][y];
        }
    }

    int left = 0;
    int right = matrixSize * (*matrixColSize) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < tmparr[mid])
        {
            right = mid - 1;
        }
        else if (target > tmparr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return true;
        }
    }
    free(tmparr);
    tmparr = NULL;
    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //matrixSize:矩阵行数
    //matrixColSize:矩阵列数
    int left = 0;
    int right = matrixSize * (*matrixColSize) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < matrix[mid / (*matrixColSize)][mid % (*matrixColSize)])
        {
            right = mid - 1;
        }
        else if (target > matrix[mid / (*matrixColSize)][mid % (*matrixColSize)])
        {
            left = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
	return 0;
}