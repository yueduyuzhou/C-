#include <stdio.h>

int main()
{   //������ 
    //int arr[10] = {1,3,5,7,9,2,4,6,8,0};    //��ʼ������

    int arr[10] = { 0 };
    int n = 0;
    for (n = 0; n < 10; n++)    //��������ʮ����
    {
        printf("�㻹û���뵽ʮ�����������:>");
        scanf("%d", &arr[n]);
    }

    int i = 0, j = 0;
    for (i = 0; i < 9; i++)    //ѡ������
    {
        for (j = i + 1; j < 10; j++)    //�Ƚ�
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    int m = 0;
    printf("���к�:>");
    for (m = 0; m < 10; m++)    //�������ʮ����
    {
        printf("%d ", arr[m]);
    }

    return 0;
}