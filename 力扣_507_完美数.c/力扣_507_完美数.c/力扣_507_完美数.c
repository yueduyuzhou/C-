//暴力循环：超出时间限制
bool checkPerfectNumber(int num) {
    int res = 0;
    int i = 1;

    while (i < num)
    {
        if (num % i == 0)
        {
            res += i;
        }
        i++;
    }

    return res == num;
}

/****************************************************************/
bool checkPerfectNumber(int num) {
    if (num == 1) { return false; }

    int sum = 1;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i != num / i) { sum += num / i; }
        }
    }

    return sum == num;
}