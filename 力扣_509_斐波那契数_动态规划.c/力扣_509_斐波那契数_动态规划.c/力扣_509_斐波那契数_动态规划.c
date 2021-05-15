/*********************************************************
*           ����1���ݹ飬��һ����¼�����¼�������ֵ
*
**********************************************************/
int helper(int n, int* memo)
{
    //�������(base case)
    if (n == 0 || n == 1) { return n; }
    //�鿴�Ƿ������
    if (memo[n] != -123) { return memo[n]; }
    //δ���������¼
    memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    //��¼������
    int* memo = (int*)malloc(sizeof(int) * (n + 1));
    assert(memo);
    //��ʼ��
    for (int i = 0; i < n + 1; i++) { memo[i] = -123; }

    return helper(n, memo);
}

/*********************************************************
*                       ����2������
* 
**********************************************************/
//��ʼ����
/*int fib(int n){
    if (n == 0) {return 0;}

    //��¼������
    int* memo = (int*)malloc(sizeof(int) * (n + 1));
    assert(memo);
    //��ʼ���±�Ϊ0��1��Ԫ��
    memo[0] = 0, memo[1] = 1;
    //����
    for (int i = 2; i < n + 1; i++) {memo[i] = memo[i - 1] + memo[i - 2];}

    return memo[n];
}*/

//�Ż��������黻����������
int fib(int n) {
    if (n == 0) { return 0; }

    //����
    int prev = 0, cur = 1, sum = 1;
    for (int i = 2; i < n + 1; i++)
    {
        sum = prev + cur;
        prev = cur;
        cur = sum;
    }

    return sum;
}