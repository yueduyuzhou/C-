#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrix == 0 || *matrixColSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int direction[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

    int rows = matrixSize, cols = matrixColSize[0];
    int tag[rows][cols];
    memset(tag, 0, sizeof(tag));
    *returnSize = rows * cols;

    int* res = (int*)malloc(sizeof(int) * rows * cols);
    assert(res);

    int i = 0, j = 0;
    int dtmp = 0; //��ǵ�ǰ����
    //int resSize = 0;  //���res�����¼�˼���Ԫ��

    for (int k = 0; k < rows * cols; k++)
    {
        //��¼Ԫ��
        res[k] = matrix[i][j];
        //Ԫ�ظ�����һ
        //resSize++;
        //����Ѽ�¼
        tag[i][j] = true;

        int nextrow = i + direction[dtmp][0];
        int nextcol = j + direction[dtmp][1];
        if (nextrow < 0 || nextrow >= rows || nextcol < 0 || nextcol >= cols || tag[nextrow][nextcol] == true)
        {
            dtmp = (dtmp + 1) % 4;
        }

        i += direction[dtmp][0];
        j += direction[dtmp][1];
    }

    return res;
}

int main()
{


	system("pause");
	return 0;
}