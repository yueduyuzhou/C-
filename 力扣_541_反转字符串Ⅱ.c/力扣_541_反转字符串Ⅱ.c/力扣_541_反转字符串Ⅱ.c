void reverSubString(char* s, int left, int right)
{
    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

char* reverseStr(char* s, int k) {
    int left = 0;
    int right = k - 1;
    int len = strlen(s);

    
    while (left < len && right < len)
    {
        reverSubString(s, left, right);
        left += (2 * k);
        right = left + k - 1;
        //printf ("%d ", left);
    }


    if (left < len && left + k >= len)  //剩余字母少于k
    {
        //printf ("%d ", left);
        reverSubString(s, left, len - 1);
    }
    else if (left < len && left + k < len && left + (2 * k) >= len)  //剩余字母多余k少于2k 
    {
        reverSubString(s, left, left + (2 * k));
    }


    return s;
}

/*********************************************************************************************************************/

void reverSubString(char* s, int size)
{
    int lentemp = size > strlen(s) ? strlen(s) : size;

    for (int i = 0; i < lentemp / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[lentemp - i - 1];
        s[lentemp - i - 1] = tmp;
    }
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);

    for (int i = 0; i < len; i += (2 * k))
    {
        reverSubString(s + i, k);
    }

    return s;
}