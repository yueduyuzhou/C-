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
    //��ʼ����ʹrightch��leftch�ֱ�ָ�����һ�����һ����Ч��ĸ
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
        //��ĸתΪСд
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
//���ÿ⺯��
bool isPalindrome(char* s) {
    /* i��j ���ȷֱ�ָ���ַ�����һ��Ԫ�غ����һ��Ԫ�� */
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        /* i ָ���Ԫ�ز�����ĸ�������ַ���i ���ƣ�ֱ�������ַ� */
        while (!isalnum(s[i]) && i < j) {
            i++;
        }

        /* j ָ���Ԫ�ز�����ĸ�������ַ���j ���ƣ�ֱ�������ַ� */
        while (!isalnum(s[j]) && i < j) {
            j--;
        }

        /* i �� j �ֱ�ָ���Ԫ��ת��ΪСд������Բ���ͬ�����ַ���Ϊ�ǻ��Ĵ� */
        if (tolower(s[i]) != tolower(s[j]) && i < j) {
            return false;
        }
    }
    return true;
}