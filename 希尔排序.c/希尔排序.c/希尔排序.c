#include <stdio.h>

//希尔排序是插入排序的一种优化。将要排序的数组分割成多组，再分别排序，最后只需全部排一次，减少了排序的次数

//void swap (int* a,int*b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//
//int main()
//{
//    int m = 0, n = 0, i = 0, j = 1;
//    m = n/2 - 1;
//
//    while (m + 1)
//    {
//        for (i = 0; i < i + m; i++)
//        {
//            for (j = 1; j*m + i < n;j++)
//            {
//                if (arr[i] > arr[i + j*m])
//                    swap(arr + i,arr + i + j*m);
//            }
//        }
//    }
//
//    return 0;
//}


void GroupSort(int* arr, int n, int start, int step)
{
    int i = 0;    //排序元素的计数器
    int j = 0;    //插入时，需要后移元素的计数器
    int tmp = 0;    //需要排序的值
    for (i = start + step; i < n; i += step)
    {
        tmp = arr[i];    //记录排序元素
        for (j = i - step; j >= 0; j -= step)    //从要排序数组最右边开始
        {
            if (arr[j] < tmp)    //被比较元素小于排序元素tmp时，跳出，否则向后元素向后移动一位 
                break;
            arr[j + step] = arr[j];
        }
        arr[j + step] = tmp;    //插入
    }
}

void ShellSort(int* arr, int n)
{
    int step = 0, i = 0;
    
    //步长每次除二
    for (step = n / 2; step > 0; step /= 2) 
    {
        //确定起始位置
        for (i = 0; i < step; i++)
        {
            GroupSort(arr, n, i, step);
        }
    }
}

//打印
void PrintArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}


int main()
{
    int arr[10] = { 2,5,84,25,9,46,3,58,93,65 };
    PrintArr(arr, 10);
    ShellSort(arr, 10);
    PrintArr(arr, 10);
    return 0;
}