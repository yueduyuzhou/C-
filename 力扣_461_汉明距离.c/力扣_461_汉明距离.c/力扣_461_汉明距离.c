//C�������ü��������λ1�ĸ�������������������򣬲�ͬλΪ1
int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}


//������ټ����������1�ĸ���
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


//���棺Brian Kernighan �㷨
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