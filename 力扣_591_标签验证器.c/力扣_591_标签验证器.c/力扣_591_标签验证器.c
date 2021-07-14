#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//判断字符串是否全大写且长度再1到9
bool upletAndlen(char* str)
{
    int len = strlen(str);
    if (len < 1 || len > 9) { return false; }

    for (int i = 0; i < len; i++)
    {
        char letter = str[i];
        if (letter < 'A' || letter > 'Z') { return false; }
    }

    return true;
}

bool isValid(char* code) {
    int len_code = strlen(code);
    char* code_cp = (char*)malloc(sizeof(char) * (len_code + 1));
    char* stack[100];
    int index_stack = 0;

    strcpy(code_cp, code);

    if (code[0] != '<') { return false; }

    for (int i = 0; i < len_code; i++)
    {
        if (code[i] == '<')
        {
            if (code[i + 1] == '!')  //cdata
            {
                if (index_stack <= 0 || strncmp(code + i + 2, "[CDATA[", 7)) { return false; }
                int j = i + 9;
                while (strncmp(code + j, "]]>", 3)) { j++; if (j == len_code) { return false; } }
                i = j + 2;
            }
            else if (code[i + 1] == '/')  //结束标签
            {
                if (index_stack <= 0 || strncmp(stack[index_stack - 1], strtok(code_cp + i + 2, ">"), strlen(stack[index_stack - 1])))
                    return false;
                //strcpy(code_cp, code);
                index_stack--;
                if (index_stack <= 0 && i + strlen(stack[index_stack]) + 3 == len_code) { return true; }
                else if (index_stack <= 0 && i + strlen(stack[index_stack]) + 3 < len_code) { return false; }
                else if (index_stack > 0 && i + strlen(stack[index_stack]) + 3 == len_code) { return false; }

                i += strlen(stack[index_stack]) + 2;
            }
            else  //开始标签
            {
                //入栈
                stack[index_stack++] = strtok(code_cp + i + 1, ">");
                //strcpy(code_cp, code);
                if (!upletAndlen(stack[index_stack - 1])) { return false; }
                i += strlen(stack[index_stack - 1]) + 1;
            }
        }
    }
    if (index_stack > 0) { return false; }
    return true;
}




int main()
{
    isValid("<DIV>This is the first line <![CDATA[<div> <![cdata]> [[]]</div>   ]]>  <DIV> <A>  <![CDATA[<b>]]>  </A>  <A> <C></C></A></DIV>    </DIV>");
	return 0;
}