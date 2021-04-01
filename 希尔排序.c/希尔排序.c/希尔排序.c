#include <stdio.h>

//ϣ�������ǲ��������һ���Ż�����Ҫ���������ָ�ɶ��飬�ٷֱ��������ֻ��ȫ����һ�Σ�����������Ĵ���

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
    int i = 0;    //����Ԫ�صļ�����
    int j = 0;    //����ʱ����Ҫ����Ԫ�صļ�����
    int tmp = 0;    //��Ҫ�����ֵ
    for (i = start + step; i < n; i += step)
    {
        tmp = arr[i];    //��¼����Ԫ��
        for (j = i - step; j >= 0; j -= step)    //��Ҫ�����������ұ߿�ʼ
        {
            if (arr[j] < tmp)    //���Ƚ�Ԫ��С������Ԫ��tmpʱ���������������Ԫ������ƶ�һλ 
                break;
            arr[j + step] = arr[j];
        }
        arr[j + step] = tmp;    //����
    }
}

void ShellSort(int* arr, int n)
{
    int step = 0, i = 0;
    
    //����ÿ�γ���
    for (step = n / 2; step > 0; step /= 2) 
    {
        //ȷ����ʼλ��
        for (i = 0; i < step; i++)
        {
            GroupSort(arr, n, i, step);
        }
    }
}

//��ӡ
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