char* getHint(char* secret, char* guess) {
    int bullsnum = 0;
    int cowsnum = 0;
    int hash[10] = { 0 };
    int i = 0, j = 0;;
    while (guess[i] != '\0')
    {
        hash[guess[i] - '0']++;
        i++;
    }

    i = 0;
    while (secret[i] != '\0')
    {
        if (secret[i] == guess[i])
        {
            bullsnum++;
            hash[secret[i] - '0']--;
            secret[i] = 'z';
        }
        i++;
    }
    i = 0;
    while (secret[i] != '\0')
    {
        if (secret[i] != 'z' && hash[secret[i] - '0'] > 0)
        {
            cowsnum++;
            hash[secret[i] - '0']--;
        }
        i++;
    }


    char temp[10], temp2[10];
    i = 0;
    while (1)
    {
        temp[i++] = bullsnum % 10 + '0';
        bullsnum /= 10;
        if (bullsnum == 0) { break; }
    }
    while (1)
    {
        temp2[j++] = cowsnum % 10 + '0';
        cowsnum /= 10;
        if (cowsnum == 0) { break; }
    }

    i--, j--;
    printf("%d%d", i, j);
    char* res = (char*)malloc(sizeof(char) * (5 + i + j));
    assert(res);
    int k = 0;
    while (i >= 0) { res[k++] = temp[i--]; }
    res[k++] = 'A';
    while (j >= 0) { res[k++] = temp2[j--]; }
    res[k++] = 'B';
    res[k] = '\0';

    //for (i = 0; i < k; i++) {printf ("%c ", res[i]);}
    return res;
}