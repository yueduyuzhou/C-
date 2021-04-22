#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������������ǵ��ڴ棬�����������
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int** res = (int**)malloc(sizeof(int*) * (rowIndex + 1));
    assert(res);

    for (int i = 0; i <= rowIndex; i++)
    {
        res[i] = (int*)malloc(sizeof(int*) * (i + 1));
        assert(res[i]);
        res[i][0] = res[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }

    return res[rowIndex];
}
/************************************************************************************************/
//�Ż�1
//���ù������飬��ʡ�ռ�
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    //�������������ֻ�Ϊ��һ��
    int* cur = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(cur);
    memset(cur, 0, sizeof(int) * (rowIndex));
    int* pre = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(pre);
    memset(pre, 0, sizeof(int) * (rowIndex));

    for (int i = 0; i <= rowIndex; i++)
    {
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i; j++)
        {
            cur[j] = pre[j - 1] + pre[j];
        }
        //�ֻ�
        int* tmp = cur;
        cur = pre;
        pre = tmp;
    }

    return pre;
}
/*************************************************************************************************/
//�Ż�2
//ʹ��һ�����飬��jԪ�ض�����һ�е�j-1��j�ĺͣ�����ʹ�Ӻ�����
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int* res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(res);
    memset(res, 0, sizeof(int) * (rowIndex + 1));

    res[0] = 1;
    for (int i = 1; i <= rowIndex; i++)
    {
        for (int j = i; j > 0; j--)
        {
            res[j] += res[j - 1];
        }
    }

    return res;
}
/************************************************************************************************/
//�Ż�3
//��ʽ���ã�ֱ���������е�ÿһ��Ԫ��
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int* res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    assert(res);
    res[0] = 1;

    for (int i = 1; i <= rowIndex; i++)
    {
        res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
    }

    return res;
}

int main()
{

	system("pause");

	return 0;
}