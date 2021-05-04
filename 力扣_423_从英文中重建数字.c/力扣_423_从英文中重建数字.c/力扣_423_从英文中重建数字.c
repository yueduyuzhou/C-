char* originalDigits(char* s) {
    //��ʼ������ĸ���ִ�����ϣ�� ��¼���ֳ��ִ������飬
    int len = strlen(s);
    int hash[26] = { 0 };
    int num[10] = { 0 };
    int i = 0;

    //��¼��ϣ����
    while (s[i] != '\0')
    {
        hash[s[i] - 'a']++;
        i++;
    }

    //����
    //�������ֵ�Ӣ�ĵ���������ĸ��¼���ֳ��ִ�������0��2��4��6��8���ж�����ĸz��w��u��x��g��������ĸ�������ⵥ�ʼ�¼����
    num[0] = hash['z' - 'a'];
    num[2] = hash['w' - 'a'];
    num[4] = hash['u' - 'a'];
    num[6] = hash['x' - 'a'];
    num[8] = hash['g' - 'a'];
    num[1] = hash['o' - 'a'] - num[2] - num[4] - num[0];
    num[3] = hash['t' - 'a'] - num[2] - num[8];
    num[5] = hash['f' - 'a'] - num[4];
    num[7] = hash['s' - 'a'] - num[6];
    num[9] = hash['i' - 'a'] - num[8] - num[6] - num[5];

    //���ַ���¼���ֵ�s
    int tmp = 0;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            s[tmp++] = '0' + i;
        }
    }
    //ע�������ַ���ĩβ��'\0'
    s[tmp] = '\0';

    return s;
}