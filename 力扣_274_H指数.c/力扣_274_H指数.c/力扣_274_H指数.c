#include <stdio.h>

//ʱ�临�Ӷ�O(n*n)
//�ռ临�Ӷ�O(1);
//�����ƽ�
int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 1 && citations[0] == 0) { return 0; }

    int num = 0;
    //int count = 0;
    int h = 0;
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < citationsSize; i++)
        {
            if (citations[i] > h) { num++; }
            //printf ("%d ",num);
            if (num > h)
            {
                flag = 1;
                h++;
                break;
            }
            printf("%d ", h);
        }
        if (flag == 0) { break; }
        num = 0;
    }

    return h;
}
/************************************************************************************/
//ʱ�临�Ӷ�O(n)
//�ռ临�Ӷ�O(1)
//�������ڱ���
int cmp(const void* a, const void* b)
{
    return (*(int*)b) - (*(int*)a);
}

int hIndex(int* citations, int citationsSize) {
    //�Ӵ�С����
    qsort(citations, citationsSize, sizeof(int), cmp);

    int h = 0;
    while (h < citationsSize && citations[h] > 0)
    {
        if (citations[h] > h) { h++; }
        else { break; }
    }

    return h;
}
int main()
{

	return 0;
}