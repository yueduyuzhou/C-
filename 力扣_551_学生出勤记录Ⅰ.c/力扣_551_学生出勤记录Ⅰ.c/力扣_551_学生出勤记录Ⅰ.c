bool checkRecord(char* s) {
    //����һ����ϣ���¼'P','L','A'���ֵĴ�����
    int hash[3] = { 0 };

    int i = 0;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case 'A':
            hash[0]++;
            break;
        case 'L':
            //��������2��'L'�������ֱ�ӷ���false
            if (s[i + 1] != '\0' && s[i + 2] != '\0' && s[i + 1] == 'L' && s[i + 2] == 'L') { return false; }
            hash[1]++;
            break;
        case 'P':
            hash[2]++;
            break;
        }

        //���ڳ���1��'A',ֱ�ӷ���false
        if (hash[0] > 1) { return false; }

        i++;
    }

    //��ѭ����ʾû�г���һ��'A'����û�г�����������'L'
    return true;
}