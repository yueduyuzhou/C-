#include <stdio.h>
#include <stdlib.h>

/******************************************************************************************************************/
//有bug
int CharToNum(char* s, int* i)
{
    int num = 0;

    while (s[(*i)] - '0' >= 0 && s[(*i)] - '0' < 10)
    {
        num += num * 10 + (s[(*i)] - '0');
        (*i)++;
    }
    (*i)--;
    return num;
}

char* solveEquation(char* equation) {
    int xcoe = 0;
    int leftorright = 1;
    int num = 0;

    int i = 0;
    while (equation[i] != '\0')
    {
        if (leftorright == 1)
        {//等号左边
            if (i - 1 >= 0 && equation[i] == 'x' && equation[i - 1] == '-') { xcoe--; }
            else if (i - 2 >= 0 && equation[i] == 'x' && equation[i - 1] - '0' >= 0 && equation[i - 1] - '0' <= 10 && equation[i - 2] == '-')
            {
                xcoe -= CharToNum(equation, (&i) - 1);
            }
            else if (i - 1 >= 0 && equation[i] == 'x' && equation[i - 1] - '0' >= 0 && equation[i - 1] - '0' <= 10)
            {
                xcoe += CharToNum(equation, (&i) - 1);
            }
            else if (equation[i] == 'x') { xcoe++; }
            else if (i - 2 >= 0 && equation[i] == 'x' && equation[i - 1] - '0' >= 0 && equation[i - 1] - '0' <= 10 && equation[i - 2] == '-')
            {
                xcoe += CharToNum(equation, (&i) - 1);
            }
            else if (i - 1 >= 0 && equation[i] == 'x' && equation[i - 1] - '0' >= 0 && equation[i - 1] - '0' <= 10)
            {
                xcoe -= CharToNum(equation, (&i) - 1);
            }
            else if (i - 1 >= 0 && equation[i] - '0' > 0 && equation[i] - '0' < 10 && equation[i - 1] == '-')
            {
                num += CharToNum(equation, &i);
            }
            else if (equation[i] - '0' > 0 && equation[i] - '0' < 10)
            {
                num += -1 * CharToNum(equation, &i);
            }
            else if (equation[i] == '=')
            {
                leftorright = 0;
            }
        }
        else
        {//等号右边
            if (equation[i] == 'x' && equation[i - 1] == '-') { xcoe++; }
            else if (equation[i] == 'x') { xcoe--; }
            else if (equation[i] - '0' > 0 && equation[i] - '0' < 10 && equation[i - 1] == '-')
            {
                num += -1 * CharToNum(equation, &i);
            }
            else if (equation[i] - '0' > 0 && equation[i] - '0' < 10)
            {
                num += CharToNum(equation, &i);
            }
        }

        i++;
    }

    if (xcoe == 0 && num == 0) { return "Infinite solutions"; }
    if (xcoe == 0 && num != 0) { return "No solution"; }

    char* res = (char*)malloc(sizeof(char) * 15);
    res[0] = 'x';
    res[1] = '=';
    sprintf(&res[2], "%d", num / xcoe);
    return res;
}

/******************************************************************************************************************/

char* solveEquation(char* equation) {
    int coe_x = 0;
    int sum = 0;
    int coefficient;
    int i = 0;
    int sign = 1; // 等号左边为1， 右边为-1
    int flag = 1; // 数字或者x系数的符号
    while (equation[i] != '\0') {
        if (equation[i] == '+') {
            flag = 1 * sign;
            i++;
        }
        else if (equation[i] == '-') {
            flag = -1 * sign;
            i++;
        }
        else if (equation[i] == 'x') {
            coe_x += flag;
            i++;
        }
        else if (isdigit(equation[i])) {
            coefficient = atoi(&equation[i]);
            while (isdigit(equation[i])) {
                i++;
            }
            if (equation[i] == 'x') {
                coe_x += flag * coefficient;
                i++;
            }
            else {
                sum += flag * coefficient;
            }
        }
        else if (equation[i] == '=') {
            flag = -1;
            sign = -1;
            i++;
        }
        else {
            i++;
        }
    }

    if (coe_x == 0) {
        char* ans;
        if (sum == 0) {
            ans = "Infinite solutions";
        }
        else {
            ans = "No solution";
        }
        return ans;
    }
    else {
        int idx = 0;
        int val = -1 * sum / coe_x;
        char* ans = (char*)malloc(sizeof(char) * (strlen(equation) + 1));
        ans[idx++] = 'x';
        ans[idx++] = '=';
        sprintf(&ans[idx], "%d", val);
        return ans;
    }
}


int main()
{
    solveEquation("2x=x");

	system("pause");
	return 0;
}