#include <stdio.h>

int main()
{    //������
    int arr[13] = { 1,3,7,11,13,17,19,21,25 };
    int num = 0, i = 0, n = 0, m = 9;

    printf("\n����ǰ������:>");
    for (i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);    //���ԭ����
    }


    printf("\n����Ҫ���������:>");
    scanf("%d", &num);    //����Ҫ���������


    if (num % 2 == 1)    //�ж������Ƿ�����������
    {
        for (i = 0; i < m; i++)
        {
            if (arr[i] > num)    //�ж�����λ��
            {
                for (n = m - 1; n >= i; n--)
                {
                    arr[n + 1] = arr[n];
                }
                arr[i] = num;
                break;
            }
            else if (num > arr[m - 1])    //�����ݷ��Ϲ����Ҵ���ԭ�������ֵ��ֱ�Ӹ�ֵ�����
            {
                arr[m] = num;    //��ֵ
            }
        }
    }
    else    //�����ݲ����Ϲ���ʱ����������
    {
        printf("\n��������ݲ��Ϸ����ٴ�����:>\n");
        main();
    }


    printf("\n������������:>");
    for (i = 0; i < m + 1; i++)
    {
        printf("%d ", arr[i]);    //������������
    }


    return 0;
}
