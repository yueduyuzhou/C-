#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//会int溢出
//void Reverse(int* arr, int size)
//{
//    int i = 0;
//    int left = 0, right = size - 1;
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//
//        left++;
//        right--;
//    }
//
//    while (i < size)
//        printf("%d", arr[i++]);
//}
//
//int IntarrToInt(int* a, int size)
//{
//    int res = 0, i = 0;
//
//    while (i < size)
//    {
//        res = res * 10 + a[i];
//        i++;
//    }
//
//    //printf ("%d ", res);
//
//    return res;
//}
//
//int* IntToIntarr(int num, int size)
//{
//    int* res = malloc(sizeof(int) * size);
//    if (res == NULL) { return NULL; }
//
//    int i = 0;
//    while (num > 0)
//    {
//        res[i] = num % 10;
//        num /= 10;
//        i++;
//    }
//
//    Reverse(res, size);
//    return res;
//}
//
//int* plusOne(int* digits, int digitsSize, int* returnSize) {
//    int flag = 0, size = digitsSize;
//    int i = 0;
//    while (i < digitsSize)
//    {
//        if (digits[i] != 9) { flag = 1; }
//        i++;
//    }
//
//    //数组变更为数字
//    int num = IntarrToInt(digits, digitsSize);
//    //判断最高位是否要进位，数字变更为数组
//    if (flag == 0) { size++; }    
//    int* res = malloc(sizeof(int) * size);
//    num++;
//    res = IntToIntarr(num, size);
//
//    *returnSize = size;
//    return res;
//}

/**************************************************************************************************************************/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int flag = 0, size = digitsSize;
    int i = 0;
    while (i < digitsSize)
    {
        if (digits[i] != 9) { flag = 1; }
        i++;
    }
    if (flag == 0) { size++; }

    int* res = malloc(sizeof(int) * size);

    i = digitsSize - 1;
    int tmp = 1;
    if (flag == 0)
    {
        while (i >= 0)
        {
            res[i + 1] = digits[i] + tmp;
            tmp = res[i + 1] / 10;
            res[i + 1] = res[i + 1] % 10;
            i--;
        }
        res[0] = 1;
    }
    else
    {
        while (i >= 0)
        {
            res[i] = digits[i] + tmp;
            tmp = res[i] / 10;
            res[i] = res[i] % 10;
            i--;
        }
    }

    *returnSize = size;
    return res;
}
/**************************************************************************************************************************/


int main()
{
    int arr[3] = { 9,9,9 };
    int size = 0;
    plusOne(arr, 3, &size);

	system("pause");
	return 0;
}