#include <stdio.h>

/*************************************************************************************************************************************/

//这个算法无法算出所有的用例
//思路：先算四个角，再算最上下左右的四行
//最后算中间部分

int** imageSmoother(int** M, int MSize, int* MColSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * MSize);
    assert(res);
    for (int i = 0; i < MSize; i++)
    {
        res[i] = (int*)malloc(sizeof(int) * *MColSize);
        assert(res[i]);
    }

    if (MSize == 1 && *MColSize == 1)
    {
        return M;
    }
    else if (MSize == 1 && *MColSize == 2)
    {
        res[0][0] = res[0][1] = (M[0][0] + M[0][1]) / 2;
        return res;
    }
    else if (MSize == 2 && *MColSize == 1)
    {
        res[0][0] = res[1][0] = (M[0][0] + M[1][0]) / 2;
        return res;
    }

    res[0][0] = (M[0][0] + M[0][1] + M[1][0] + M[1][1]) / 4;
    res[0][*MColSize - 1] = (M[0][*MColSize - 1] + M[0][*MColSize - 2] + M[1][*MColSize - 1] + M[1][*MColSize - 2]) / 4;
    res[0][0] = (M[MSize - 1][0] + M[MSize - 2][0] + M[MSize - 1][1] + M[MSize - 2][1]) / 4;
    res[0][0] = (M[MSize - 1][*MColSize - 1] + M[MSize - 2][*MColSize - 1] + M[MSize - 1][*MColSize - 2] + M[MSize - 2][*MColSize - 2]) / 4;

    for (int i = 1; i < MSize - 1; i++)
    {
        res[i][0] = (M[i - 1][0] + M[i][0] + M[i + 1][0] + M[i - 1][1] + M[i][1] + M[i + 1][1]) / 6;
        res[i][*MColSize - 1] = (M[i - 1][*MColSize - 1] + M[i][*MColSize - 1] + M[i + 1][*MColSize - 1] + M[i - 1][*MColSize - 2] + M[i][*MColSize - 2] + M[i + 1][*MColSize - 2]) / 6;
    }
    for (int i = 1; i < *MColSize; i++)
    {
        res[0][i] = (M[0][i - 1] + M[0][i] + M[0][i - 2] + M[1][i - 1] + M[1][i] + M[1][i - 2]) / 6;
        res[MSize - 1][i] = (M[MSize - 1][i - 1] + M[MSize - 1][i] + M[MSize - 1][i - 2] + M[MSize - 2][i - 1] + M[MSize - 2][i] + M[MSize - 2][i - 2]) / 6;
    }

    for (int i = 1; i < MSize - 1; i++)
    {
        for (int j = 1; j < *MColSize - 1; j++)
        {
            res[i][j] = (M[i - 1][j - 1] + M[i - 1][j] + M[i - 1][j + 1] + M[i][j - 1] + M[i][j] + M[i][j + 1] + M[i + 1][j - 1] + M[i + 1][j] + M[i + 1][j + 1]) / 9;
        }
    }

    *returnSize = MSize;
    **returnColumnSizes = *MColSize;
    return res;

}

/***********************************************************************************************************************************************************************************/

//评论区解
//遍历整个矩阵，在判断每个矩阵的周围调元格是否存在

/*int** imageSmoother(int** M, int MSize, int* MColSize, int* returnSize, int** returnColumnSizes) {

    int i, j, cnt = 0, sum = 0;
    int **re = (int **)malloc(sizeof(int *) * (MSize));
*/
//    *returnSize = MSize;  /* 设置返回矩阵的行数 */
//    *returnColumnSizes = MColSize;  /* 设置返回矩阵的列数 */

//    for (i = 0; i < MSize; i++) {    /* 为每一行的行指针分配空间 */
//        re[i] = (int *)malloc(sizeof(int) * MColSize[0]);   /* 因为每一行的列数相等，所以MColSize[0、1、2...]都可以 */
//    }

    /* 暴力解法，分别遍历每一个元素
     * 以此判断是否在边缘以选择加数
     */
     /*for (i = 0; i < MSize; i++) {
         for(j = 0; j < MColSize[0]; j++) {

             sum = M[i][j];
             cnt = 1;

             if (i - 1 >= 0) {  //上
                 cnt++;
                 sum += M[i-1][j];
             }

             if(i + 1 <= MSize - 1) {  //下
                 cnt++;
                 sum += M[i+1][j];
             }

             if (j - 1 >= 0) {  //左
                 cnt++;
                 sum += M[i][j-1];
             }

             if (j + 1 <= MColSize[0] - 1) {  //右
                 cnt++;
                 sum += M[i][j+1];
             }

             if (i - 1 >= 0 && j - 1 >= 0) {  //左上
                 cnt++;
                 sum += M[i-1][j-1];
             }

             if (i - 1 >= 0 && j + 1 <= MColSize[0] - 1) {  //右上
                 cnt++;
                 sum += M[i-1][j+1];
             }

             if (i + 1 <= MSize - 1 && j - 1 >= 0) {  //左下
                 cnt++;
                 sum += M[i+1][j-1];
             }

             if (i + 1 <= MSize - 1 && j + 1 <= MColSize[0] - 1) {  //右下
                 cnt++;
                 sum += M[i+1][j+1];
             }

             re[i][j] = sum / cnt;
         }
     }

     return re;
 }*/

int main()
{
	return 0;
}