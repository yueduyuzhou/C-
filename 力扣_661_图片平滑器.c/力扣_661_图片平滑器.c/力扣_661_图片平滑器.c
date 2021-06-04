#include <stdio.h>

/*************************************************************************************************************************************/

//����㷨�޷�������е�����
//˼·�������ĸ��ǣ��������������ҵ�����
//������м䲿��

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

//��������
//���������������ж�ÿ���������Χ��Ԫ���Ƿ����

/*int** imageSmoother(int** M, int MSize, int* MColSize, int* returnSize, int** returnColumnSizes) {

    int i, j, cnt = 0, sum = 0;
    int **re = (int **)malloc(sizeof(int *) * (MSize));
*/
//    *returnSize = MSize;  /* ���÷��ؾ�������� */
//    *returnColumnSizes = MColSize;  /* ���÷��ؾ�������� */

//    for (i = 0; i < MSize; i++) {    /* Ϊÿһ�е���ָ�����ռ� */
//        re[i] = (int *)malloc(sizeof(int) * MColSize[0]);   /* ��Ϊÿһ�е�������ȣ�����MColSize[0��1��2...]������ */
//    }

    /* �����ⷨ���ֱ����ÿһ��Ԫ��
     * �Դ��ж��Ƿ��ڱ�Ե��ѡ�����
     */
     /*for (i = 0; i < MSize; i++) {
         for(j = 0; j < MColSize[0]; j++) {

             sum = M[i][j];
             cnt = 1;

             if (i - 1 >= 0) {  //��
                 cnt++;
                 sum += M[i-1][j];
             }

             if(i + 1 <= MSize - 1) {  //��
                 cnt++;
                 sum += M[i+1][j];
             }

             if (j - 1 >= 0) {  //��
                 cnt++;
                 sum += M[i][j-1];
             }

             if (j + 1 <= MColSize[0] - 1) {  //��
                 cnt++;
                 sum += M[i][j+1];
             }

             if (i - 1 >= 0 && j - 1 >= 0) {  //����
                 cnt++;
                 sum += M[i-1][j-1];
             }

             if (i - 1 >= 0 && j + 1 <= MColSize[0] - 1) {  //����
                 cnt++;
                 sum += M[i-1][j+1];
             }

             if (i + 1 <= MSize - 1 && j - 1 >= 0) {  //����
                 cnt++;
                 sum += M[i+1][j-1];
             }

             if (i + 1 <= MSize - 1 && j + 1 <= MColSize[0] - 1) {  //����
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