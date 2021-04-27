int lengthOfLastWord(char* s) {
    //只有一个空格的情况
    if (s[0] == ' ' && s[1] == '\0') { return 0; }

    int tmp = 0;
    int lastCount = 0;

    while (s[tmp])
    {
        if (s[tmp + 1] == '\0')
        {
            while (tmp > 0 && s[tmp] == ' ')
            {
                tmp--;
            }

            while (tmp >= 0 && s[tmp--] != ' ')
            {
                lastCount++;
            }
            break;
        }
        tmp++;
    }

    return lastCount;
}







int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int cnt = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
        if (s[i] != ' ')
            cnt++;
        if (s[i] == ' ' && 0 != cnt)
            break;
    }

    return cnt;
}