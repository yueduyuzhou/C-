char* reverseWords(char* s) {
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    int stmp = len - 1;
    int restmp = 0;

    char* res = (char*)malloc(sizeof(char) * (len + 1));
    assert(res);

    //跳过前面的空格
    //while (s[stmp] == ' '){stmp++;}


    while (stmp >= 0)
    {
        if (s[stmp] == ' ')
        {
            stmp--;
        }
        else
        {
            right = stmp;
            while (stmp >= 0 && s[stmp] != ' ')
            {
                stmp--;
            }
            left = stmp + 1;

            while (left <= right)
            {
                res[restmp++] = s[left++];
            }
            res[restmp++] = ' ';
        }
    }


    if (restmp > 0 && res[restmp - 1] == ' ')
    {
        res[restmp - 1] = '\0';
    }
    else
    {
        res[restmp] = '\0';
    }

    return res;
}