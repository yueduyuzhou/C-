typedef struct Romannum
{
    char* r;
    int val;
}Romannum;

int romanToInt(char* s) {
    //开辟一个结构体数组，保存罗马数字与阿拉伯数字的对应关系
    Romannum* tab = (Romannum*)malloc(sizeof(Romannum) * 4);
    //初始化
    int i = 0;
    while (i < 4)
    {
        tab[i].r = (char*)malloc(sizeof(char));
        i++;
    }
    //tab[0].r = "I", tab[0].val = 1;
    tab[0].r = 'V', tab[0].val = 5;
    //tab[2].r = "X", tab[2].val = 10;
    tab[1].r = 'L', tab[1].val = 50;
    //tab[4].r = "C", tab[4].val = 100;
    tab[2].r = 'D', tab[2].val = 500;
    tab[3].r = 'M', tab[3].val = 1000;

    i = 0;
    int j = 0;
    int res = 0;
    while (s[i] != '\0')
    {
        j = 0;
        while (j < 4)
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] != '\0' && s[i + 1] == 'V') { res += 4; i++; }
                else if (s[i + 1] != '\0' && s[i + 1] == 'X') { res += 9; i++; }
                else { res += 1; }
                break;
            }
            else if (s[i] == 'X')
            {
                if (s[i + 1] != '\0' && s[i + 1] == 'L') { res += 40; i++; }
                else if (s[i + 1] != '\0' && s[i + 1] == 'C') { res += 90; i++; }
                else { res += 10; }
                break;
            }
            else if (s[i] == 'C')
            {
                if (s[i + 1] != '\0' && s[i + 1] == 'D') { res += 400; i++; }
                else if (s[i + 1] != '\0' && s[i + 1] == 'M') { res += 900; i++; }
                else { res += 100; }
                break;
            }
            else
            {
                if (tab[j].r == s[i])
                {
                    res += tab[j].val;
                    break;
                }
            }

            j++;
        }

        i++;
    }

    return res;
}
/***************************************************************************************************************************/

int romanToInt(char* s) {
    int i = 0;
    int res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] != '\0' && s[i + 1] == 'V') { res += 4; i++; }
            else if (s[i + 1] != '\0' && s[i + 1] == 'X') { res += 9; i++; }
            else { res += 1; }
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] != '\0' && s[i + 1] == 'L') { res += 40; i++; }
            else if (s[i + 1] != '\0' && s[i + 1] == 'C') { res += 90; i++; }
            else { res += 10; }
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] != '\0' && s[i + 1] == 'D') { res += 400; i++; }
            else if (s[i + 1] != '\0' && s[i + 1] == 'M') { res += 900; i++; }
            else { res += 100; }
        }
        else if (s[i] == 'V')
        {
            res += 5;
        }
        else if (s[i] == 'L')
        {
            res += 50;
        }
        else if (s[i] == 'D')
        {
            res += 500;
        }
        else if (s[i] == 'M')
        {
            res += 1000;
        }

        i++;
    }

    return res;
}