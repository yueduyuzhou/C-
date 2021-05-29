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
    int count = 0; //��¼��������
    int lastfmu = 1; //��¼ͨ�ֺ��ĸ
    int lastfzi = 0; //��¼ͨ�ֺ����
    int tmp = 0; //��ʱ����

    char* res = (char*)malloc(sizeof(char) * 12); //���
    frac* p = (frac*)malloc(sizeof(frac) * 10); //��ŷ���

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i + 1] == '/')
        {
            if (i - 1 >= 0 && expression[i] == '0' && expression[i - 1] == '1') //����Ϊ10
            {
                p[count].fzi = 10;
                p[count].fzixb = i - 1;
            }
            else //����Ϊ0 ~ 9
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
        //ͨ�ַ���
        p[i].fzi *= (tmp / p[i].fmu);
        //������Ϊ��
        if (p[i].fzixb - 1 >= 0 && expression[p[i].fzixb - 1] == '-')
        {
            p[i].fzi *= -1;
        }
        //�����ۼ�
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

    //������ӷ�ĸ�����Լ��
    tmp = gcd(abs(lastfzi), lastfmu);

    if (lastfzi < 0)
        sprintf(res, "-%d/%d", abs(lastfzi) / tmp, lastfmu / tmp);
    else
        sprintf(res, "%d/%d", lastfzi / tmp, lastfmu / tmp);

    return res;
}