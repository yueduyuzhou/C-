//����
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
    if ((dividend ^ divisor) < 0) { // ��������һ��Ϊ����
        sign = -1;
    }
    if (divisor == INT_MIN) { // �����߽�ֵ���⴦��
        if (dividend == INT_MIN) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dividend == INT_MIN) { // �������߽�ֵ���⴦��
        if (divisor == -1) {
            return INT_MAX;
        }
        else if (divisor == 1) {
            return INT_MIN;
        }
        dividend += abs(divisor); // ��ִ��һ�μӲ���������absת�����
        cnt++;
    }
    int a = abs(dividend);
    int b = abs(divisor);
    while (a >= b) {
        int c = 1;
        int s = b;
        // ��ָ�������ٱƽ����Ա���ִ�г�ʱ
        while (s < (a >> 1)) { // �ƽ���һ�룬ͬʱ�������
            s += s;
            c += c;
        }
        cnt += c;
        a -= s;
    }
    return (sign == -1) ? -cnt : cnt;
}

/**************************************************************************************************/