#include <stdio.h>

//int Age_change(int* age,int i)
//{
//   if (i < 5)
//   {
//      *age += 2;
//      i++;
//      Age_change(&age,i);  
//   }
//   return age;
//}

void main()
{
    int age = 10, i = 0, n = 0;
    printf("������������");
    scanf_s("%d", &n);
    if (n >= 1 && n < 1000000000)   //��֤�������ֵ�ںϷ���Χ��    
    {
        for (i = 1; i < n; i++)   //�ӵ�һ���˿�ʼ���㵽���һ��
        {
            age += 2;   //�����2
        }
        printf("���һ������%d�ꡣ", age);   
    }
    else  //��ֵ���Ϸ����ٴ����룬ֱ���Ϸ�
    {
        printf("��������������Ϸ������ٴ����룡\n");
        main();
    }
}