//错误
int divide(int dividend, int divisor) {
    if (dividend == 0) { return 0; }
    if (dividend == divisor) { return 1; }
    if (divisor == 1 || divisor == -1) { return dividend * divisor; }

    int flag = 1;
    if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) { flag = 1; }
    else { flag = -1; }

    dividend = abs(dividend);
    divisor = abs(divisor);
    int res = 0;

    while (dividend > divisor)
    {

        dividend -= divisor;
        res++;
    }

    return res * flag;
}

/**************************************************************************************************/

int divide(int dividend, int divisor) {
    int cnt = 0;
    int sign = 1;
    if ((dividend ^ divisor) < 0) { // 两数任意一个为负数
        sign = -1;
    }
    if (divisor == INT_MIN) { // 除数边界值特殊处理
        if (dividend == INT_MIN) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dividend == INT_MIN) { // 被除数边界值特殊处理
        if (divisor == -1) {
            return INT_MAX;
        }
        else if (divisor == 1) {
            return INT_MIN;
        }
        dividend += abs(divisor); // 先执行一次加操作，避免abs转换溢出
        cnt++;
    }
    int a = abs(dividend);
    int b = abs(divisor);
    while (a >= b) {
        int c = 1;
        int s = b;
        // 需指数级快速逼近，以避免执行超时
        while (s < (a >> 1)) { // 逼近至一半，同时避免溢出
            s += s;
            c += c;
        }
        cnt += c;
        a -= s;
    }
    return (sign == -1) ? -cnt : cnt;
}

/**************************************************************************************************/