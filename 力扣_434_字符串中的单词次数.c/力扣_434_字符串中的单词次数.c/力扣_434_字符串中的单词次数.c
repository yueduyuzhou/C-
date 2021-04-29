int countSegments(char* s) {
    int count = 0;

    while (*s)
    {
        //当前字符不为空格且下一个字符是空格或结束符，count+1
        if (*s != ' ' && (*(s + 1) == ' ' || *(s + 1) == '\0')) { count++; }

        s++;
    }

    return count;
}


int countSegments(char* s) {
    //if (s == NULL || (s[1] == '\0' && s[0] == ' ')) {return 0;}

    int tmp = 0;
    int count = 0;

    while (s[tmp])
    {
        if (s[tmp] != ' ' && (s[tmp + 1] == ' ' || s[tmp + 1] == '\0'))
        {
            count++;
        }

        tmp++;
    }

    return count;
}