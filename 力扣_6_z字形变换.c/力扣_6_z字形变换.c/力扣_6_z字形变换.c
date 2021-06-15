#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************/
//找出跨度的变化规律
char* convert(char* s, int numRows) {
    if (numRows == 1) { return s; }

    int len_s = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len_s + 2));
    int index_s = 0, j = 2 * numRows - 2;
    int index_res = 0;
    int flag = 1;
    while (s[index_s] != '\0' && index_s < 2 * numRows - 2)
    {
        //按行收录变形后的元素
        int tmp_s = index_s;
        
        while (tmp_s < len_s)
        {
            res[index_res++] = s[tmp_s];
            if (flag != 1) { j += flag; flag *= -1; }
            tmp_s += j;
        }

        //收录完，重新计算跨度
        if (index_s + 2 == numRows) { j = 2 * numRows - 2; flag = 1; }
        else { j -= 2; flag = -2; }

        index_s++;
    }
    res[index_res] = '\0';

    return res;
}

/**************************************************************************************************************************/

char* convert(char* s, int numRows) {
    numRows--;
    if (!numRows)
        return s;
    else {
        char* s1, * s2;
        int i, j, slen;
        bool flag;
        slen = strlen(s);
        s1 = malloc(sizeof(char) * (slen + 1));
        j = 0;
        s2 = s;
        while (s2 - s < slen) {
            s1[j] = *s2;
            s2 += numRows * 2;
            j++;
        }
        for (i = 1; i < numRows; i++) {
            s2 = s + i;
            flag = 0;
            while (s2 - s < slen) {
                s1[j] = *s2;
                s2 += flag ? 2 * i : 2 * (numRows - i);
                flag = !flag;
                j++;
            }
        }
        s2 = s + numRows;
        while (s2 - s < slen) {
            s1[j] = *s2;
            s2 += numRows * 2;
            j++;
        }
        s1[j] = 0;
        return s1;
    }
}

int main()
{
    convert("PAYPALISHIRING", 4);


    system("pause");
    return 0;
}