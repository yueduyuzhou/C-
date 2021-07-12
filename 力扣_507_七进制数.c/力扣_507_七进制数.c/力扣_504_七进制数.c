char* convertToBase7(int num) {
    if (num == 0) { return "0"; }

    char* res = (char*)calloc(12, sizeof(char));
    if (num < 0)
    {
        strcat(res, "-");
    }

    num = abs(num);
    char arr[12] = { 0 };
    int i = -1;
    while (num > 0)
    {
        arr[++i] = num % 7 + '0';
        num /= 7;
    }
    while (i >= 0)
    {
        strncat(res, arr + i, 1);
        i--;
    }

    return res;

}