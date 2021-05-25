bool checkRecord(char* s) {
    //给定一个哈希表记录'P','L','A'出现的次数，
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
            //连续超过2个'L'的情况，直接返回false
            if (s[i + 1] != '\0' && s[i + 2] != '\0' && s[i + 1] == 'L' && s[i + 2] == 'L') { return false; }
            hash[1]++;
            break;
        case 'P':
            hash[2]++;
            break;
        }

        //存在超过1个'A',直接返回false
        if (hash[0] > 1) { return false; }

        i++;
    }

    //出循环表示没有超过一个'A'并且没有超过连续两个'L'
    return true;
}