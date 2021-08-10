//½ØÈ¡×Ö·û´®
char* getNum(char* num, int head, int tail)
{
    if (tail >= strlen(num) || head < 0) { return NULL; }
    char* n = malloc(tail - head + 2);
    int index = 0;
    while (index <= tail - head)
    {
        n[index] = num[head + index];
        index++;
    }

    n[index] = '\0';
    return n;
}

//·­×ª×Ö·û´®
char* Reverse(char* s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++, right--;
    }
    return s;
}

//Á½¸ö×Ö·û´®Ïà¼Ó
char* add(char* num, int i, int j, int k)
{
    char* a = getNum(num, i, j);
    char* b = getNum(num, j + 1, k);

    if (a == NULL || b == NULL) { return NULL; }

    int len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char* sum = malloc(len + 1);
    int len_a = strlen(a) - 1;
    int len_b = strlen(b) - 1;
    int z = 0;
    int carry = 0;

    while (len_a >= 0 && len_b >= 0)
    {
        char tmp = a[len_a] + b[len_b] - '0' + carry;
        carry = 0;
        if (tmp - '0' >= 10) { tmp -= 10; carry = 1; }
        sum[z++] = tmp;
        len_a--, len_b--;
    }

    if (len_a >= 0)
    {
        while (len_a >= 0)
        {
            char tmp = a[len_a] + carry;
            carry = 0;
            if (tmp - '0' >= 10) { tmp -= 10; carry = 1; }
            sum[z++] = tmp;
            len_a--;
        }
    }
    else if (len_b >= 0)
    {
        while (len_b >= 0)
        {
            char tmp = b[len_b] + carry;
            carry = 0;
            if (tmp - '0' >= 10) { tmp -= 10; carry = 1; }
            sum[z++] = tmp;
            len_b--;
        }
    }

    if (carry != 0)
    {
        sum = realloc(sum, len + 2);
        sum[z++] = '1';
        //sum[i] = '\0';
    }
    sum[z] = '\0';

    sum = Reverse(sum);

    return sum;
}

bool dfs(char* num, int i, int j, int k)
{
    int len = strlen(num);

    if ((num[i] == '0' && i != j) || (num[j + 1] == '0' && k > j + 1)) { return false; }

    char* sum = add(num, i, j, k);
    if (sum == NULL) { return false; }

    int n = strlen(sum);
    char* next = getNum(num, k + 1, k + n);

    if (next == NULL || strcmp(next, sum) != 0) { return false; }
    else if (k + n == len - 1) { return true; }

    return dfs(num, j + 1, k, k + n);
}

bool isAdditiveNumber(char* num) {
    int i = 0;
    for (int j = i; j <= strlen(num) / 2; j++)
    {
        for (int k = j + 1; k < strlen(num); k++)
        {
            if (dfs(num, i, j, k)) { return true; }
        }
    }
    return false;
}

bool CheckABC(int aIndex, int aLen, int bIndex, int bLen, int cIndex, int cLen, char* num, int len)
{
    char a;
    char b;
    char c;
    char flag = 0;
    char ab;

    if ((num[cIndex] == '0') && (cLen > 1)) {
        return false;
    }

    if ((num[bIndex] == '0') && (bLen > 1)) {
        return false;
    }

    while ((aLen >= 1) || (bLen >= 1) || (cLen >= 1)) {
        aLen--;
        bLen--;
        cLen--;

        a = (aLen >= 0) ? num[aIndex + aLen] : '0';
        b = (bLen >= 0) ? num[bIndex + bLen] : '0';
        c = (cLen >= 0) ? num[cIndex + cLen] : '0';

        ab = a + b + flag;
        flag = 0;
        if ((ab > '9' + '0') && (ab == c + 10 + '0')) {
            flag = 1;
        }
        else if (ab != c + '0') {
            return false;
        }
    }

    return true;
}


/*******************************************************************************************************************************************/

bool checkNumber(int aIndex, int aLen, int bIndex, int bLen, char* num, int len)
{
    int cIndex = bIndex + bLen;
    int cLen = (bLen > aLen) ? bLen : aLen;
    bool ret = false;

    if (cLen + cIndex > len) {
        return false;
    }

    if (CheckABC(aIndex, aLen, bIndex, bLen, cIndex, cLen, num, len)) {
        if (len == cIndex + cLen) {
            return true;
        }
        ret = checkNumber(bIndex, bLen, cIndex, cLen, num, len);
        if (ret == true) {
            return true;
        }
    }

    cLen++;
    if (cLen + cIndex > len) {
        return false;
    }

    if (CheckABC(aIndex, aLen, bIndex, bLen, cIndex, cLen, num, len)) {
        if (len == cIndex + cLen) {
            return true;
        }
        ret = checkNumber(bIndex, bLen, cIndex, cLen, num, len);
        if (ret == true) {
            return true;
        }
    }

    return false;
}

bool isAdditiveNumber(char* num) {
    int numLen = strlen(num);
    int aIndex;
    int aLen;
    int bIndex;
    int bLen;
    bool ret;

    for (aLen = 1; aLen <= numLen / 2; aLen++) {
        aIndex = 0;
        bIndex = aIndex + aLen;
        for (bLen = 1; bLen <= (numLen - aLen) / 2; bLen++) {
            ret = checkNumber(aIndex, aLen, bIndex, bLen, num, numLen);
            if (ret == true) {
                return true;
            }
        }
    }

    return false;
}
