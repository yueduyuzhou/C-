#define LEN 64
char* complexNumberMultiply(char* num1, char* num2) {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int lastx = 0, lasty = 0;
    char prev[LEN] = { 0 };
    char tail[LEN] = { 0 };
    char* res = (char*)calloc(LEN, sizeof(char));
    assert(res);
    
    //复数系数转化为数字
    sscanf(num1, "%d+%d", &x1, &y1);
    sscanf(num2, "%d+%d", &x2, &y2);
    //根据公式计算结果复数的系数
    lastx = x1 * x2 - y1 * y2;
    lasty = x1 * y2 + x2 * y1;
    //使用sprintf组合为结果
    sprintf(res, "%d+%di", lastx, lasty);

    return res;
}

//自己实现细节，效率会上升

#define MAX_SIZE 20
int Abs(int num)
{
    if (num < 0) {
        return num * (-1);
    }
    return num;
}

char* NumtoString(int num)
{
    int i = 0;
    int index = 0;
    int count = 0;
    int sign = 1;
    char temp[MAX_SIZE] = { 0 };
    char* ch = (char*)malloc(sizeof(char) * MAX_SIZE);
    memset(ch, 0, MAX_SIZE);
    if (num == 0) {
        ch[index++] = '0';
    }
    if (num < 0) {
        sign = -1;
        num = Abs(num);
    }
    while (num > 0) {
        temp[count++] = num % 10 + 48;
        num = num / 10;
    }
    temp[count] = '\0';
    if (sign == -1) {
        ch[index++] = '-';
    }
    for (i = count - 1; i >= 0; i--) {
        ch[index++] = temp[i];
    }
    ch[index] = '\0';
    return ch;
}
void GetAAndB(char* s, int* a, int* b)
{
    int sign = 1;
    int tempA = 0;
    int tempB = 0;
    int temp = 0;
    while (*s != '\0') {
        if (*s == '-') {
            sign = -1;
        }
        else if (*s == '+') {
            tempA = tempA + temp * (sign);
            sign = 1;
            temp = 0;
        }
        else if (*s == 'i') {
            tempB = tempB + temp * (sign);
            temp = 0;
        }
        else {
            temp = temp * 10 + (*s - 48);
        }
        s++;
    }
    *a = tempA + temp * (sign);
    *b = tempB;
    return;
}
char* complexNumberMultiply(char* a, char* b)
{
    char* result = (char*)malloc(sizeof(char) * MAX_SIZE);
    memset(result, 0, MAX_SIZE);
    int aX = 0;
    int aY = 0;
    int bX = 0;
    int bY = 0;
    int rX;
    int rY;
    int index = 0;
    GetAAndB(a, &aX, &aY);
    GetAAndB(b, &bX, &bY);
    rX = aX * bX - aY * bY;
    rY = aX * bY + aY * bX;
    sprintf(result, "%s%s%s%s", NumtoString(rX), "+", NumtoString(rY), "i");
    return result;
}


