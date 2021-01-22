#include <stdio.h>

#define Max_size 5

struct student
{
    char name[10];
    int num;
    char sex[10];
    int age;
    float score;
};

void input(struct student m[])    //输入结构体数组个分量
{
    for (int i = 0; i < Max_size; i++)
    {
        printf("依次输入name num sex age score:>\n");
        scanf("%s%d%s%d%f", m[i].name, &m[i].num, m[i].sex, &m[i].age, &m[i].score);
    }
    printf("\n\n");
}

void output(struct student m[])    //输出整个结构体数组
{
    printf("name\tnum\tsex\tage\tscore\n");
    for (int i = 0; i < Max_size; i++)
    {
        printf("%s\t%d\t%s\t%d\t%f\n", m[i].name, m[i].num, m[i].sex, m[i].age, m[i].score);
    }
    printf("\n\n");
}

int main()
{
    struct student m[Max_size];    //创建结构体数组
    input(m);
    output(m);
    return 0;
}