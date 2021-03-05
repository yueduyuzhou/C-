#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int KSize = 0;
    int k = K;
    while (k)    //����K��λ��
    {
        KSize++;
        k /= 10;
    }
    
    //��̬����һ���ȴ���λ��+1��С���ڴ�ռ�
    int len = ASize > KSize ? ASize : KSize;
    int* arr = (int*)malloc(sizeof(int) * (len + 1));

    //arri��Ŀ��������±�(�ӵ�һ��Ԫ�ؿ�ʼ)��i��A������±�(�����һ��Ԫ�ؿ�ʼ)��nextnum�ǽ�λ(��sum>1ʱnextnumΪ1������Ϊ0)
    int arri = 0;
    int i = ASize - 1;
    int nextnum = 0;
    while (len--)
    {
        int a = 0;
        if (i >= 0)
            a = A[i--];

        //�����
        int sum = a + K % 10 + nextnum;
        K /= 10;

        //��sum����9ʱ��nextnum��Ϊ1��sum��10��С��9ʱ��nextnumΪ0
        if (sum > 9)
        {
            nextnum = 1;
            sum -= 10;
        }
        else
        {
            nextnum = 0;
        }

        //sum�������arr����
        arr[arri++] = sum;
    }
    //����ĩβ��Ҫ����1
    if (nextnum == 1)
        arr[arri++] = 1;

    //��תarr
    int left = 0;
    int right = arri - 1;
    while (left < right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++, right--;
    }
   
    *returnSize = arri;
    return arr;
}

int main()
{
    int A[] = { 2,1,5 };
    int K = 806;
    int* returnSize = (int*)malloc(sizeof(int));
    assert(returnSize);
    int* arr = addToArrayForm(A, 3, K, returnSize);
    for (int i = 0; i < *returnSize; i++)
    {
        printf("%d", arr[i]);
    }

    free(returnSize);
    free(arr);
	return 0;
}