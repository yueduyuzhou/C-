bool hasAlternatingBits(int n) {
    int prev = n & 1;
    int cur = 0;
    n >>= 1;
    while (n)
    {
        //�õ�n�����һ��λ
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