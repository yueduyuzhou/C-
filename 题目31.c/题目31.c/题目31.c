#include <stdio.h>

int main()
{
    char first_letter_day, second_letter_day;
    printf("�������ڵ�����ĸ��");
    scanf_s("%c", &first_letter_day,1);
    char waste = getchar();   //�������������һ��\n

    if (first_letter_day == 'M')     //�ж�����ĸѡ���ӡ����
    {
        printf("����һ\n");
    }
    else if (first_letter_day == 'T')
    {
        printf("���������ڵĵڶ�����ĸ��");    //�������ڶ�������������ĸ��ͬ�����ݵڶ�����ĸ�ٽ����ж�
        scanf_s("%c", &second_letter_day,1);
        if (second_letter_day == 'u')
        {
            printf("���ڶ�\n");
        }
        else if (second_letter_day == 'h')
        {
            printf("������\n");
        }
    }
    else if (first_letter_day == 'W')
    {
        printf("������\n");
    }
    else if (first_letter_day == 'F')
    {
        printf("������\n");
    }
    else     
    {
        printf("���������ڵĵڶ�����ĸ��");    //����������������������ĸ��ͬ�����ݵڶ�����ĸ�ٽ����ж�
        scanf_s("%c", &second_letter_day,1);
        if (second_letter_day == 'a')
        {
            printf("������\n");
        }
        else if (second_letter_day == 'u')
        {
            printf("������\n");
        }
    }
    //main ();   //�ظ�ִ��
    return 0;
}