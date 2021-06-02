#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int countSubstrings(char* s) {
    int len_s = strlen(s);
    int count_manacher = 0;

    int i = 0;
    while (i < 2 * len_s - 1)
    {
        int l = i / 2;
        int r = l + (i % 2);
        while (l >= 0 && r < len_s && s[l] == s[r])
        {
            l--, r++;
            count_manacher++;
        }
        i++;
    }

    return count_manacher;
}

/************************************************************************************************************************************/

int countSubstrings(char* s) {
    int len_s = strlen(s);
    char* new_s = (char*)malloc(sizeof(char) * (len_s * 2 + 4));
    //初始化字符数组
    new_s[0] = '$';
    new_s[1] = '#';
    int i = 0;
    while (i < len_s) {
        new_s[2 * i + 2] = s[i];
        new_s[2 * i + 3] = '#';
        i++;
    }
    new_s[2 * len_s + 2] = '!';
    new_s[2 * len_s + 3] = '\0';
    len_s = 2 * len_s + 3;

    int f[len_s];
    memset(f, 0, sizeof(f));
    int imax = 0, rmax = 0, count_manacher = 0;

    i = 1;
    while (i < len_s)
    {
        f[i] = (i <= rmax) ? fmin(rmax - i + 1, f[2 * imax - 1]) : 1;
        //中心拓展
        while (new_s[i + f[i]] == new_s[i - f[i]]) { f[i]++; }

        if (i + f[i] - 1 > rmax)
        {
            imax = i;
            rmax = i + f[i] - i;
        }

        count_manacher += (f[i] / 2);

        i++;
    }

    free(new_s);
    new_s = NULL;
    return count_manacher;
}

int main()
{
    countSubstrings("qweassaew");
	//system ("pause");
	exit(0);
}