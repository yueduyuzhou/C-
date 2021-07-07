int findComplement(int num) {
    int res = 0;
    int count = 0;
    while (num)
    {
        if (!(num & 1))
        {
            res += (1 << count);
        }
        count++;
        num >>= 1;
    }
    return res;
}