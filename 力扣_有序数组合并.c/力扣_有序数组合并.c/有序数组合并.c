#include <stdio.h>


void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    // write code here
    int i = 1;
    int flag = 1;
    int a = m + n;
    while (1)
    {
        if (A[m - 1] > B[n - 1])
        {
            A[ALen - i] = A[m - 1];
            i++, flag = 1;
            if (m - 1 != 0)
            {
                m--;
                if (m - 1 == 0)
                    continue;
            }
        }
        else if (A[m - 1] <= B[n - 1])
        {
            A[ALen - i] = B[n - 1];
            i++, flag = 0;
            if (n - 1 != 0)
            {
                n--;
                if (n - 1 == 0)
                    continue;
            }
        }
        if (A[m - 1] == A[0])
        {
            if (flag == 1)
            {
                while (n - 1 >= 0)
                {
                    A[ALen - i] = B[n - 1];
                    i++, n--;
                    flag = 3;
                }
            }
        }
        if (B[n - 1] == B[0])
        {
            if (flag == 0)
            {
                while (m - 1 >= 0)
                {
                    A[ALen - i] = A[m - 1];
                    i++, m--;
                    flag = 3;
                }
            }
        }
        if (flag == 3)
        {
            for (i = 0; i < a; i++)
            {
                A[i] = A[ALen - a + i];
            }
            break;
        }
    }
}

void Print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int a[20] = { 1,5,6,8,61,70 };
    int b[10] = { 3,4,5,7,12,121 };
    int m = 6;
    int n = 6;

    merge(a, 20, m, b, 10, n);
    Print(a,m + n);
    return 0;
}