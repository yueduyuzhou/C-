#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ?  (a) : (b))
int lengthLongestPath(char* input) {
    int ret = 0;
    int folders[100] = { 0 };
    bool isFile = false;
    int len = strlen(input);
    int cntT = 0;
    int cntW = 0;
    for (int i = 0; i <= len; i++) {
        if (i < len && input[i] == '\t') {
            cntT++;
        }
        else if (i == len || input[i] == '\n') {
            if (isFile) {
                ret = MAX(ret, cntW + (cntT > 0 ? folders[cntT - 1] : 0) + cntT);
                isFile = false;
            }
            else {
                folders[cntT] = cntW + (cntT > 0 ? folders[cntT - 1] : 0);
            }
            cntW = 0;
            cntT = 0;
        }
        else {
            if (input[i] == '.') {
                isFile = true;
            }
            cntW++;
        }
    }
    return ret;
}

int main()
{
    char a[] = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    lengthLongestPath(a);

	return 0;
}