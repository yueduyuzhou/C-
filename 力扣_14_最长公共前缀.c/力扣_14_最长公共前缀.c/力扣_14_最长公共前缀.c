#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/***************************************************************************************************************/
//有错
//char* longestCommonPrefix(char** strs, int strsSize) {
//    char* res = (char*)malloc(sizeof(char) * 2);
//    assert(res);
//    res[0] = '\0';
//    res[1] = '\0';
//    int ressize = 2;
//
//
//    for (int j = 0; strs[0][j] != '\0'; j++)
//    {
//        int flag = 0;
//        //tmp存放每一列第一个字符
//        char tmp = strs[0][j];
//        for (int i = 1; i < strsSize; i++)
//        {
//            if (strs[i][j] != tmp)
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag == 0)
//        {
//            res = (char*)realloc(res, sizeof(char) * (ressize + 1));
//            assert(res);
//            ressize++;
//            res[ressize - 2] = strs[0][j];
//            res[ressize - 1] = '\0';
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    return res;
//}

/***************************************************************************************************************/

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) { return ""; }

    int length = strlen(strs[0]);
    for (int i = 0; i < length; i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strsSize; j++)
        {
            if (i == strlen(strs[j]) || strs[j][i] != ch)
            {
                char* res = (char*)malloc(sizeof(char) * (i + 1));
                res[i] = '\0';
                for (int tmp = 0; tmp < i; tmp++)
                {
                    res[tmp] = strs[0][tmp];
                }
                return res;
            }
        }
    }

    return strs[0];
}


int main()
{ 
    char** strs = (char**)malloc(sizeof(char*) * 3);
    strs[0] = (char*)malloc(sizeof(char) * 9);
    strs[1] = (char*)malloc(sizeof(char) * 7);
    strs[2] = (char*)malloc(sizeof(char) * 11);
    strs[0] = "flkkower";
    strs[1] = "flkkow";
    strs[2] = "flkkkkkight";
    //printf ("%c", res);
    longestCommonPrefix(strs, 3);
	return 0;
}