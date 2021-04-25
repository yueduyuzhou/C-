/********************************************************************************************************************************************/

bool numORletter(char s)
{
    int tmp = s;
    if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122) || (tmp >= 48 && tmp <= 57))
    {
        return true;
    }
    return false;
}

bool isPalindrome(char* s) {
    if (strlen(s) == 1) { return true; }
    //初始化，使rightch和leftch分别指向最后一个或第一个有效字母
    int leftch = 0;
    int rightch = strlen(s) - 1;
    while (!numORletter(s[leftch]) && leftch < rightch) { leftch++; }
    while (!numORletter(s[rightch]) && leftch < rightch) { rightch--; }
    //printf ("%c", s[rightch]);
    //printf ("%c", s[leftch]);
    //printf ("%d", leftch);

    bool res = true;
    while (leftch < rightch)
    {
        //字母转为小写
        s[leftch] = tolower(s[leftch]);
        s[rightch] = tolower(s[rightch]);

        if (s[leftch] != s[rightch])
        {
            res = false;
            break;
        }
        leftch++;
        rightch--;
        while (!numORletter(s[leftch]) && leftch < rightch) { leftch++; }
        while (!numORletter(s[rightch]) && leftch < rightch) { rightch--; }
    }

    return res;
}

/********************************************************************************************************************************************/
//运用库函数
bool isPalindrome(char* s) {
    /* i、j 首先分别指向字符串第一个元素和最后一个元素 */
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        /* i 指向的元素不是字母或数字字符，i 右移，直到遇到字符 */
        while (!isalnum(s[i]) && i < j) {
            i++;
        }

        /* j 指向的元素不是字母或数字字符，j 左移，直到遇到字符 */
        while (!isalnum(s[j]) && i < j) {
            j--;
        }

        /* i 和 j 分别指向的元素转化为小写，如果仍不相同，该字符串为非回文串 */
        if (tolower(s[i]) != tolower(s[j]) && i < j) {
            return false;
        }
    }
    return true;
}