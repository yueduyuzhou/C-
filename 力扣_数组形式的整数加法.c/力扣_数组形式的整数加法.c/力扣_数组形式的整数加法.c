#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int KSize = 0;
    int k = K;
    while (k)    //计算K的位数
    {
        KSize++;
        k /= 10;
    }
    
    //动态开辟一个比大数位数+1大小的内存空间
    int len = ASize > KSize ? ASize : KSize;
    int* arr = (int*)malloc(sizeof(int) * (len + 1));

    //arri是目标数组的下标(从第一个元素开始)，i是A数组的下标(从最后一个元素开始)，nextnum是进位(当sum>1时nextnum为1，否则为0)
    int arri = 0;
    int i = ASize - 1;
    int nextnum = 0;
    while (len--)
    {
        int a = 0;
        if (i >= 0)
            a = A[i--];

        //计算和
        int sum = a + K % 10 + nextnum;
        K /= 10;

        //当sum大于9时，nextnum变为1，sum减10，小于9时，nextnum为0
        if (sum > 9)
        {
            nextnum = 1;
            sum -= 10;
        }
        else
        {
            nextnum = 0;
        }

        //sum逆序存入arr数组
        arr[arri++] = sum;
    }
    //处理末尾需要进的1
    if (nextnum == 1)
        arr[arri++] = 1;

    //逆转arr
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