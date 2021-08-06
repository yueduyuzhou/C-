
void add(int* num) {
    int res = 0;
    while (*num)
    {
        res += *num % 10;
        *num /= 10;
    }
    *num = res;
}

int addDigits(int num) {
    int i = 0;
    while (num >= 10)
    {
        add(&num);
    }

    return num;
}