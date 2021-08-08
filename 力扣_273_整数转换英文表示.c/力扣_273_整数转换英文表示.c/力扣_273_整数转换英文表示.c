/****************************************************************************************************************************************************/
//未完善
char* numberToWords(int num) {
    char digit[10][10] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
    char tenth[12][14] = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
    char tenth2[12][12] = { " "," ","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

    char* res = ();

    int fthree = num % 1000;
    num /= 1000;
    int sthree = num % 1000;
    num /= 1000;
    int tthree = num % 1000;
    num /= 1000;
    int lthree = num % 1000;
    num /= 1000;

    char* fch = (char*)calloc(4, sizeof(char));
    sprintf(fch, "%d", fthree);
    char* sch = (char*)calloc(4, sizeof(char));
    sprintf(sch, "%d", sthree);
    char* tch = (char*)calloc(4, sizeof(char));
    sprintf(tch, "%d", tthree);
    char* lch = (char*)calloc(4, sizeof(char));
    sprintf(lch, "%d", lthree);

    int flag = 0;
    if (lthree != 0)
    {
        flag = 1;
        sprintf(res, "%d", digit[lch[0] - '0']);
        strcat(res, " Billion ");
    }

    if (tthree != 0)
    {
        int j = strlrn(tch);
        if (flag == 1 || j == 3)
        {
            strcat(res, digit[tch[0] - '0']);
            strcat(res, " Hundred ");
            strcat(res, tenth[tch[1] - '0']);
            strcat(res, " ");
            strcat(res, tenth2[tch[2] - '0']);
            strcat(res, " Million ");
        }
        else
        {
            int i = 0;
            if (j == 2)
            {
                strcat(res, tenth[tch[1] - '0']);
                strcat(res, " ");
                strcat(res, tenth2[tch[2] - '0']);
                i++;
            }
            else if (j == 1)
            {
                strcat(res, tenth2[tch[2] - '0']);
            }
            strcat(res, " Million ");
        }
    }

}

/****************************************************************************************************************************************************/
char unit[5][12] = { " Hundred"," Thousand"," Million"," Billion"," Trillion" };
char digit[10][10] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
char tenth[12][14] = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
char tenth2[12][12] = { " "," ","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };


struct SElemType {
	int unitCount; //段位 
	int num;       //每段位的数字，三位数字 
};

//=======================================
// 该函数将一个百位以内的数转换为英文
// =====================================
char* convert(int num)
{
	char* retArr = (char*)malloc(50);
	retArr[0] = '\0';

	if (!num)
		return retArr;
	int temp;
	temp = num / 100;
	if (temp)
	{
		strcat(retArr, digit[temp]);
		strcat(retArr, " Hundred");
	}
	temp = num % 100;
	if (temp >= 20)
	{
		int temp1;
		temp1 = temp / 10;
		if (retArr[0] != '\0')
			strcat(retArr, " ");
		strcat(retArr, tenth2[temp1]);
		temp1 = temp % 10;
		if (temp1)
		{
			strcat(retArr, " ");
			strcat(retArr, digit[temp1]);
		}
	}
	else if (temp >= 10)
	{
		if (retArr[0] != '\0')
			strcat(retArr, " ");
		strcat(retArr, tenth[temp - 10]);

	}
	else if (temp > 0)
	{
		if (retArr[0] != '\0')
			strcat(retArr, " ");
		strcat(retArr, digit[temp]);
	}

	return retArr;
}

char* numberToWords(int num) {
	char* retArr = (char*)malloc(1000);
	struct SElemType tmpStack[100];
	int top = 0;
	struct SElemType e;

	retArr[0] = '\0';

	if (!num)
	{
		strcat(retArr, "Zero");
		return retArr;
	}

	char* tmpArr;

	int i = 0;
	while (num)                        //将整数三位一组，存放到堆栈中
	{
		e.unitCount = i;        //每组数据对应的单位索引，1-千，2-百万，3-十亿，依次类推
		e.num = num % 1000;
		tmpStack[top++] = e;
		num = num / 1000;
		i++;
	}

	while (top > 0)
	{
		e = tmpStack[--top];
		tmpArr = convert(e.num);
		if (tmpArr[0] != '\0')
		{
			strcat(retArr, tmpArr);
			if (e.unitCount)
			{
				strcat(retArr, unit[e.unitCount]);
			}
		}
		if ((top - 1 >= 0) && tmpStack[top - 1].num > 0)  //如果堆栈中还有非零数据，则添加一个空格
			strcat(retArr, " ");

	}
	return retArr;
}

/****************************************************************************************************************************************************/
//最高效

const char* ge[] = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
};
const char* shi1[] = {
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
};
const char* shi2[] = {
    "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
};

#define N 2000
char result[N] = { 0 };
bool appended = false;

void baishige(int n)
{
    int b = (n / 100) % 10;
    n %= 100;
    if (b) { // 百位
        if (appended) {
            strcat(result, " ");
        }
        strcat(result, ge[b]);
        strcat(result, " Hundred");
        appended = true;
    }
    int s = n / 10;
    n %= 10;
    if (s) { // 十位
        if (appended) {
            strcat(result, " ");
        }
        if (s == 1) {
            strcat(result, shi1[n]);
            n = 0; // 不需要再看个位了
        }
        else {
            strcat(result, shi2[s]);
        }
        appended = true;
    }
    if (n) { // 个位
        if (appended) {
            strcat(result, " ");
        }
        strcat(result, ge[n]);
        appended = true;
    }
}

#define BILLION 1000000000
#define MILLION 1000000
#define THOUSAND 1000
char* numberToWords(int n)
{
    if (n <= 0) {
        strcpy(result, "Zero");
        return result;
    }
    appended = false;
    memset(result, 0, sizeof(result));
    int b = n / BILLION;
    n %= BILLION;
    if (b) { // BILLION
        baishige(b);
        strcat(result, " Billion");
    }
    int m = n / MILLION;
    n %= MILLION;
    if (m) { // MILLION
        baishige(m);
        strcat(result, " Million");
    }
    int t = n / THOUSAND;
    n %= THOUSAND;
    if (t) { // 千位
        baishige(t);
        strcat(result, " Thousand");
    }
    baishige(n);
    return result;
}
