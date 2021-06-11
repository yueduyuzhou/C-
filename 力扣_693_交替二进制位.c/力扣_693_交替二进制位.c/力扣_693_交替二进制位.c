bool hasAlternatingBits(int n) {
    int prev = n & 1;
    int cur = 0;
    n >>= 1;
    while (n)
    {
        //拿到n的最后一个位
        cur = n & 1;
        if (prev == cur)
        {
            break;
        }
        n >>= 1;
        prev = cur;
    }
    if (n) { return false; }
    else { return true; }
}