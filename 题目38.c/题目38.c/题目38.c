#include <stdio.h>

int main()
{
    int sum = 0;
    //int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};    //��������
    int arr[3][3] = { 0 };    
    int i = 0, j = 0;
    for (i = 0; i < 3; i++)        //��i��
    {                              //������
        for (j = 0; j < 3; j++)    //��j��
        {
            printf("�����%d�е�%d������:>", i, j);
            scanf("%d", &arr[i][j]);    //��ֵ
        }
    }
    printf("\n��������:>\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", arr[i][j]);    //�����ݰ������ʽ���
        }
        printf("\n");
    }
    sum = arr[0][0] + arr[0][2] + arr[2][0] + arr[2][2];    //��ԽǺ�ֵ
    printf("\n�Խ���ֵ���λΪ:>%d\n", sum);

    return 0;
}