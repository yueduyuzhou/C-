#include <stdio.h>

/*int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    if (mat == NULL || matSize == 0 || *matColSize == 0) {return NULL;}

    int ressize = *returnSize = matSize * *matColSize;
    int* res = (int*)malloc(sizeof(int) * ressize);
    assert(res);
    //printf("%d %d",*returnSize, ressize);

    int direction[2][2] = {{1,-1}, {-1,1}};
    //int direction[2][2] = {{-1,1}, {1,-1}};

    int dtmp = 0;
    int i = 0, j = 1;

    res[0] = mat[0][0];

    for (int k = 1; k < ressize; k++)
    {
        res[k] = mat[i][j];

        int nextrow = i + direction[dtmp][0];
        int nextcol = j + direction[dtmp][1];
        if ((nextrow < 0 || nextrow >= matSize) && (nextcol >= 0 && nextcol < *matColSize))
        {
            j++;
            dtmp = (dtmp + 1) % 2;
        }
        else if ((nextcol < 0 || nextcol >= matSize) && (nextrow >= 0 && nextrow < matSize))
        {
            i++;
            dtmp = (dtmp + 1) % 2;
        }
        else
        {
            i += direction[dtmp][0];
            j += direction[dtmp][1];
        }

        /*if (i != 0 && j == 0)
        {
            i++;
            j--;
        }
        else if (j != 0 && i == 0)
        {
            i--;
            j++;
        }
        else
        {

        }
    }

    return res;
}*/

/****************************************************************************************************************************************/

int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) {
        return NULL;
    }
    int total = matrixSize * matrixColSize[0];
    int* res = (int*)malloc(sizeof(int) * total);
    int clockwise = 1, row = 0, col = 0;
    while (returnSize[0] < total) {
        // 1.��������Խ���
        do {
            res[returnSize[0]++] = matrix[row][col];
            row -= clockwise;  // ������������ƶ�
            col += clockwise;
        } while (0 <= row && row < matrixSize && 0 <= col && col < matrixColSize[0]);

        // 2.���ݷ���ȷ����һ���սǵ������
        if (clockwise == 1) {
            if (col == matrixColSize[0]) {
                // ������������У������� 2���������� row = 0
                row += 2;
                col = matrixColSize[0] - 1;
            }
            else row = 0;
        }
        else {
            if (row == matrixSize) {
                // �����������У������� 2���������� col = 0
                col += 2;
                row = matrixSize - 1;
            }
            else col = 0;
        }
        clockwise *= -1;  // ת��
    }
    return res;
}


int main()
{

	system("pause");
	return 0;
}