#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Ѱ������
int Find(int x, int arr[])
{
    if (arr[x] == x) { return x; }

    return arr[x] = Find(arr[x], arr);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int* arr = (int*)malloc(sizeof(int) * isConnectedSize);// * (*isConnectedColSize));
    assert(arr);
    //int arrSize = isConnectedSize;// * (*isConnectedColSize);
    int i, j;
    int res = isConnectedSize;
    //��ʼ����������
    for (i = 0; i < isConnectedSize; i++) { arr[i] = i; }

    //�������󣬱����Խ��ߵ�һ��ͺ�
    for (i = 0; i < isConnectedSize; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (isConnected[i][j] == 0) { continue; }
            if (Find(arr[i], arr) != Find(arr[j], arr))
            {
                arr[Find(i, arr)] = arr[Find(j, arr)];
                res--;
            }
        }
    }
    free(arr);
    arr = NULL;
    return res;
}

int main()
{
	return 0;
}