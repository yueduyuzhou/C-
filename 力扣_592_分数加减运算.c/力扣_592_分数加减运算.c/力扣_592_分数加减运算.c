typedef struct fraction {
    int fzi;
    int fmu;
    int fzixb;
}frac;

int gcd(int a, int b)
{
    int tmp = 1;
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    while (a % b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return tmp;
}

char* fractionAddition(char* expression) {
    int count = 0; //记录分数个数
    int lastfmu = 1; //记录通分后分母
    int lastfzi = 0; //记录通分后分子
    int tmp = 0; //临时数据

    char* res = (char*)malloc(sizeof(char) * 12); //结果
    frac* p = (frac*)malloc(sizeof(frac) * 10); //存放分数

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i + 1] == '/')
        {
            if (i - 1 >= 0 && expression[i] == '0' && expression[i - 1] == '1') //分子为10
            {
                p[count].fzi = 10;
                p[count].fzixb = i - 1;
            }
            else //分子为0 ~ 9
            {
                p[count].fzi = expression[i] - '0';
                p[count].fzixb = i;
            }
        }
        else if (i - 1 > 0 && expression[i - 1] == '/')
        {
            if (expression[i] == '1' && expression[i + 1] == '0')
            {
                p[count].fmu = 10;
            }
            else
            {
                p[count].fmu = expression[i] - '0';
            }
            lastfmu *= p[count].fmu;
            count++;
        }
    }

    tmp = lastfmu;

    for (int i = 0; i < count; i++)
    {
        //通分分子
        p[i].fzi *= (tmp / p[i].fmu);
        //当分数为负
        if (p[i].fzixb - 1 >= 0 && expression[p[i].fzixb - 1] == '-')
        {
            p[i].fzi *= -1;
        }
        //分子累加
        lastfzi += p[i].fzi;
    }

    if (lastfzi == lastfmu)
    {
        sprintf(res, "%d/%d", 1, 1);
        return res;
    }

    if (lastfzi == 0)
    {
        sprintf(res, "%d/%d", 0, 1);
        return res;
    }

    //计算分子分母的最大公约数
    tmp = gcd(abs(lastfzi), lastfmu);

    if (lastfzi < 0)
        sprintf(res, "-%d/%d", abs(lastfzi) / tmp, lastfmu / tmp);
    else
        sprintf(res, "%d/%d", lastfzi / tmp, lastfmu / tmp);

    return res;
}