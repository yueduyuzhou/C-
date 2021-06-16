#define INT_MAX 2147483647
#define INT_MIN -2147483648

int myAtoi(char* s) {
    int flag = 1;
    int len = strlen(s);
    int i = 0;
    //跳过前导空格
    while (s[i] == ' ') { i++; len--; }
    //是否为负数
    if (s[i] == '-')
    {
        flag = -1;
        i++;
        len--;
    }
    else if (s[i] == '+')
    {
        flag = 1;
        i++;
        len--;
    }

    while (s[i] == '0') { i++; len--; }
    //printf ("%d ", i);
    //记录数字
    long double resnum = 0;
    while (s[i] != '\0' && s[i] - '0' >= 0 && s[i] - '0' < 10)
    {
        resnum = resnum * 10 + (s[i] - '0');
        if (flag * resnum < INT_MIN) { return INT_MIN; }
        else if (flag * resnum > INT_MAX) { return INT_MAX; }
        i++;
    }

    /*while (s[i] - '0' >= 0 && s[i] - '0' < 10)
    {
        if (flag == 1 && resnum > INT_MAX / 10) {return INT_MAX;}
        else if (flag == -1 && resnum < INT_MIN / 10) { return INT_MIN;}
        resnum = resnum * 10 + (s[i] - '0');
        i++;
    }*/

    resnum *= flag;

    return resnum;
}



/*************************************************************************************************************************************************/




int myAtoi(char* s) {
    int flag = 1;
    int len = strlen(s);
    int i = 0;
    //跳过前导空格
    while (s[i] == ' ') { i++; len--; }
    //是否为负数
    if (s[i] == '-')
    {
        flag = -1;
        i++;
        len--;
    }
    else if (s[i] == '+')
    {
        flag = 1;
        i++;
        len--;
    }

    while (s[i] == '0') { i++; len--; }
    //printf ("%d ", i);
    //记录数字
    long double resnum = 0;
    while (s[i] != '\0' && s[i] - '0' >= 0 && s[i] - '0' < 10)
    {
        resnum = resnum * 10 + (s[i] - '0');
        if (flag * resnum < -2147483648) { return -2147483648; }
        else if (flag * resnum > 2147483647) { return 2147483647; }
        i++;
    }

    resnum *= flag;

    return resnum;
}