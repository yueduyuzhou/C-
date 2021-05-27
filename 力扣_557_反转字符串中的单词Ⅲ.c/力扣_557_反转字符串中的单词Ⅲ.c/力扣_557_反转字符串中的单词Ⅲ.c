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

char* reverseWords(char* s) {
    int left = 0;
    int right = 0;
    int len = strlen(s);

    for (right = 0; right < len; right++)
    {
        if (s[right] == ' ')
        {
            reverSubString(s, left, right - 1);
            left = right + 1;
        }
    }
    reverSubString(s, left, len - 1);

    return s;
}