#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************/
//1.暴力法
#define min(a,b) (a) < (b) ? (a) : (b)
#define max(a,b) (a) > (b) ? (a) : (b)

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    //printf ("%d", matrixSize;)
    //printf ("%d", *matrixColSize;)    
    if (*matrixColSize <= 0) { return 0; }

    //int** tmp = matrix;
    int maxside = 0;
    int side = 0, res = 0;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {

            if (matrix[i][j] == '1')
            {
                side = 1;
                maxside = min(matrixSize - i, *matrixColSize - j);
                //printf ("%d", maxside);

                for (int k = 1; k < maxside; k++)
                {
                    int flag = 0;
                    if (matrix[i + k][j + k] == '1') //&& i + k < *matrixColSize && j + k < matrixSize)
                    {
                        //printf("%d", side);
                        for (int a = i; a < i + k; a++)
                        {
                            if (matrix[a][j + k] == '0') { flag = 1; }
                            //printf ("%c", matrix[a][j + k]);
                        }
                        for (int a = j; a < j + k; a++)
                        {
                            if (matrix[i + k][a] == '0') { flag = 1; }
                            //printf ("%c", matrix[i + k][a]);
                        }

                    }
                    else { flag = 1; }
                    if (flag == 1) { break; }
                    else if (flag == 0) { side++; }
                }
                //printf ("%d ", side);
            }
            //printf ("%d ", side);
            res = max(res, side);
            side = 0;

        }
    }
    return res * res;
}
/************************************************************************************************/
//2.动态规划
int min(int a, int b, int c)
{
    return a < (b < c ? b : c) ? a : (b < c ? b : c);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (*matrixColSize <= 0) { return 0; }

    int** dp = (int**)malloc(sizeof(int*) * matrixSize);
    assert(dp);
    for (int i = 0; i < matrixSize; i++)
    {
        dp[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
        assert(dp[i]);
    }

    int maxside = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                }

                maxside = max(maxside, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return maxside * maxside;
}



int main()
{
    char** temp = (char**)malloc(sizeof(char*) * 6);
    for (int i = 0; i < 6; i++)
    {
        temp[i] = (char*)malloc(sizeof(char) * 6);
    }
    //temp[0][0] = '1', temp[0][1] = '0', temp[0][2] = '1', temp[0][3] = '1', temp[0][4] = '0', temp[0][5] = '1';
    //temp[1][0] = '1', temp[1][1] = '1', temp[1][2] = '1', temp[1][3] = '1', temp[1][4] = '1', temp[1][5] = '1';
    //temp[2][0] = '0', temp[2][1] = '1', temp[2][2] = '1', temp[2][3] = '0', temp[2][4] = '1', temp[2][5] = '1';
    //temp[3][0] = '1', temp[3][1] = '1', temp[3][2] = '1', temp[3][3] = '0', temp[3][4] = '1', temp[3][5] = '0';
    //temp[4][0] = '0', temp[4][1] = '1', temp[4][2] = '1', temp[4][3] = '1', temp[4][4] = '1', temp[4][5] = '1';
    //temp[5][0] = '1', temp[5][1] = '1', temp[5][2] = '0', temp[5][3] = '1', temp[5][4] = '1', temp[5][5] = '1';

    int a = 6;
    int res = maximalSquare(temp, 6, &a);
    printf("%d", res);
	return 0;
}