char* originalDigits(char* s) {
    //初始量：字母出现次数哈希表， 记录数字出现次数数组，
    int len = strlen(s);
    int hash[26] = { 0 };
    int num[10] = { 0 };
    int i = 0;

    //记录哈希数据
    while (s[i] != '\0')
    {
        hash[s[i] - 'a']++;
        i++;
    }

    //核心
    //根据数字的英文单词特殊字母记录数字出现次数：（0，2，4，6，8）有独有字母z，w，u，x，g，其他字母根据特殊单词记录次数
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

    //用字符记录数字到s
    int tmp = 0;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            s[tmp++] = '0' + i;
        }
    }
    //注意在新字符串末尾加'\0'
    s[tmp] = '\0';

    return s;
}