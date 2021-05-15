/*********************************************************
*           方法1，递归，用一个记录数组记录已算过的值
*
**********************************************************/
int helper(int n, int* memo)
{
    //基本情况(base case)
    if (n == 0 || n == 1) { return n; }
    //查看是否已算过
    if (memo[n] != -123) { return memo[n]; }
    //未算过计算后记录
    memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    //记录的数组
    int* memo = (int*)malloc(sizeof(int) * (n + 1));
    assert(memo);
    //初始化
    for (int i = 0; i < n + 1; i++) { memo[i] = -123; }

    return helper(n, memo);
}

/*********************************************************
*                       方法2，迭代
* 
**********************************************************/
//初始代码
/*int fib(int n){
    if (n == 0) {return 0;}

    //记录的数组
    int* memo = (int*)malloc(sizeof(int) * (n + 1));
    assert(memo);
    //初始化下标为0和1的元素
    memo[0] = 0, memo[1] = 1;
    //迭代
    for (int i = 2; i < n + 1; i++) {memo[i] = memo[i - 1] + memo[i - 2];}

    return memo[n];
}*/

//优化，把数组换成三个变量
int fib(int n) {
    if (n == 0) { return 0; }

    //迭代
    int prev = 0, cur = 1, sum = 1;
    for (int i = 2; i < n + 1; i++)
    {
        sum = prev + cur;
        prev = cur;
        cur = sum;
    }

    return sum;
}