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

void input(struct student m[])    //����ṹ�����������
{
    for (int i = 0; i < Max_size; i++)
    {
        printf("��������name num sex age score:>\n");
        scanf("%s%d%s%d%f", m[i].name, &m[i].num, m[i].sex, &m[i].age, &m[i].score);
    }
    printf("\n\n");
}

void output(struct student m[])    //��������ṹ������
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
    struct student m[Max_size];    //�����ṹ������
    input(m);
    output(m);
    return 0;
}