#include <stdio.h>

int main()
{
    int num = 0, arr[5], i = 0, a = 0;
    printf("����һ����λ��:");
    scanf_s("%d��", &num);
    if (num > 9999 && num < 100000)
    {
        a = num;   //������ֵ

        for (i = 0; i < 5; i++)
        {
            arr[i] = num % 10;   //�ֱ��ȡ����ʮ���٣�ǧ����λ����������
            num = num / 10;   //ɾ��ĩλ
        }
        if (arr[0] == arr[4] && arr[1] == arr[3])   //�жϸ�λ����λ��ʮλ��ǧλ�Ƿ���ͬ
        {
            printf("%d�ǻ�������\n", a);
        }
        else
        {
            printf("%d���ǻ�������\n", a);
        }
    }
    else
    {
        printf ("���������ֵ������Ҫ��\n");
        printf("������");
    }
    //main();   //�ظ�ִ��
    return 0;
}