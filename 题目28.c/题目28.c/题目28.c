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
    printf("请输入人数：");
    scanf_s("%d", &n);
    if (n >= 1 && n < 1000000000)   //保证输入的数值在合法范围内    
    {
        for (i = 1; i < n; i++)   //从第一个人开始计算到最后一人
        {
            age += 2;   //年龄加2
        }
        printf("最后一个人是%d岁。", age);   
    }
    else  //数值不合法后再次输入，直至合法
    {
        printf("你输入的人数不合法，请再次输入！\n");
        main();
    }
}