#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//ʱ�临�Ӷ�̫��
int bulbSwitch(int n) {
    if (n == 0) { return 0; }

    int res = 0;
    bool* arr = (bool*)malloc(n * sizeof(bool));
    if (!arr) { return -1; }

    memset(arr, 0, sizeof(bool) * n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j + i < n; j += (i + 1))
        {
            arr[j + i] = !arr[j + i];
        }
    }
    int k = 0;
    while (k < n)
    {
        if (!arr[k]) { res++; }
        k++; 
    }

    return res;
}


//��ѧ����ȫƽ����������
int bulbSwitch(int n) {
    int res = 1;
    while (res * res <= n) { res++; }
    res--;
    return res;
}



int main()
{
    bulbSwitch(123578633);

	return 0;
}