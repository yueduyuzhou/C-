#include <stdio.h>

int main()
{
	int letter = 0, space = 0, num = 0, others = 0; //保存字符
	char temp;
	
	for (;(temp = getchar())!= 10;)
	{
		if (temp >= 65 && temp <= 90 || temp >= 97 && temp <= 122)  //筛选出字母
			letter++;  //记录字母个数
		else if (temp == 32)  //筛选出空格
			space++;  //记录空格个数
		else if (temp >= 48 && temp <= 57)  //筛选出数字
			num++;  //记录数字个数
		else  
			others++;  //记录其他字符个数
	}
	printf("字符串中有%d个字母，%d个空格，%d个数字以及%d个其他字符。\n", letter, space, num, others);
	//main();  //需要重复使用是解除注释
	return 0;
}