#include <stdio.h>
#include <stdlib.h>
//#include <>

int calPoints(char** ops, int opsSize) {
    int res = 0;
    int i = 0;
    int index_arr = 0;
    int* arr = (int*)malloc(sizeof(int) * opsSize);
    if (!arr) { return -1; }

    for (i = 0; i < opsSize; i++)
    {
        switch (ops[i][0]) {
        case '+':
            arr[index_arr] = arr[index_arr - 1] + arr[index_arr - 2];
            index_arr++;
            break;
        case 'D':
            arr[index_arr] = arr[index_arr - 1] * 2;
            index_arr++;
            break;
        case 'C':
            index_arr--;
            break;
        default:
            arr[index_arr] = atoi(ops[i]);
            index_arr++;
        }
    }

    for (i = 0; i < index_arr; i++) { res += arr[i]; }

    return res;
}

int main()
{
    char** a = (char**)malloc(sizeof(char*) * 5);
    a[0] = "5";
    a[1] = "2";
    a[2] = "C";
    a[3] = "D";
    a[4] = "+";

    calPoints(a, 5);
	return 0;
}