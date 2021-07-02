int calculate(char* s) {
    int len_s = strlen(s);
    int arr[len_s], top = 0;
    char preSign = '+';
    int num = 0;
    for (int i = 0; i < len_s; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (int)(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == len_s - 1) {
            switch (preSign) {
            case '+':
                arr[top++] = num;
                break;
            case '-':
                arr[top++] = -num;
                break;
            case '*':
                arr[top - 1] *= num;
                break;
            default:
                arr[top - 1] /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    int ret = 0;
    for (int i = 0; i < top; i++) {
        ret += arr[i];
    }
    return ret;
}