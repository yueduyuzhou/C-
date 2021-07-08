//C语言内置计算二进制位1的个数，传入两参数的异或，不同位为1
int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}


//先异或，再计算异或结果中1的个数
int hammingDistance(int x, int y) {
    intxor = x ^ y;
    int res_count = 0;
    while (xor)
    {
        if (xor &1 == 1)
        {
            res_count++;
        }
        xor >>= 1;
    }
    return res_count;
}


//神奇：Brian Kernighan 算法
int hammingDistance(int x, int y) {
    intxor = x ^ y;
    int res_count = 0;
    while (xor)
    {
        xor = xor &(xor -1);
        res_count++;
    }
    return res_count;
}