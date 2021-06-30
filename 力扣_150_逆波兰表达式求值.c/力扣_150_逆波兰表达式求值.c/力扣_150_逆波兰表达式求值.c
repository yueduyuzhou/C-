#include <stdio.h>
#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    int index_tok = 0;  //表示字符串数组的第一个字符串
    int index_arr = 0;

    int* arr = (int*)malloc(sizeof(int) * tokensSize);
    if (!arr) { return 0; }

    while (index_tok < tokensSize)
    {
        if ((tokens[index_tok][0] != '+' && tokens[index_tok][0] != '-' && tokens[index_tok][0] != '*' && tokens[index_tok][0] != '/') ||  strlen(tokens[index_tok]) > 1)
        {
            arr[index_arr++] = atoi(tokens[index_tok]);
        }
        else
        {
            switch (tokens[index_tok][0]) {
            case '+':
                if (index_arr - 2 < 0) { arr[index_arr - 1] = 0 + arr[index_arr - 1]; break; }
                arr[index_arr - 2] = arr[index_arr - 2] + arr[index_arr - 1];
                index_arr--;
                break;
            case '-':
                if (index_arr - 2 < 0) { arr[index_arr - 1] = 0 - arr[index_arr - 1]; break; }
                arr[index_arr - 2] = arr[index_arr - 2] - arr[index_arr - 1];
                index_arr--;
                break;
            case '*':
                if (index_arr - 2 < 0) { arr[index_arr - 1] = 0; break; }
                arr[index_arr - 2] = arr[index_arr - 2] * arr[index_arr - 1];
                index_arr--;
                break;
            case '/':
                if (index_arr - 2 < 0) { arr[index_arr - 1] = 0; break; }
                arr[index_arr - 2] = arr[index_arr - 2] / arr[index_arr - 1];
                index_arr--;
                break;
            }
        }

        index_tok++;
    }

    return arr[0];
}

int main()
{
    char* a = "3";
    char* b = "-4";
    char* c = "+";
    char** d = (char**)malloc(sizeof(char*) * 3);
    d[0] = a;
    d[1] = b;
    d[2] = c;
    evalRPN(d, 3);
	return  0;
}