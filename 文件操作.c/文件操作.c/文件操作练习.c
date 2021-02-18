#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main()
//{
//	//创建一个FILE指针fp，指向以'w'只写的形式打开的1.txt文件
//	FILE* fp = fopen("1.txt", "w");
//	//判断文件打开情况
//	if (fp == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	//接收第一个字符
//	char ch = getchar();
//	//循环到'#'结束
//	while (ch != '#')
//	{
//		fputc(ch, fp);    //把ch字符写入fp指向的文件
//		putchar(ch);      //把ch显示到屏幕上
//		ch = getchar();   //接收下一个字符
//
//	}
//
//	fclose(fp);    //关闭fp指向的文件
//	fp = NULL;   
//	return 0;
//}

//int main()
//{
//	FILE* fp = fopen("1.txt", "r");
//	if (fp == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	char ch = fgetc(fp);    //接收fp指向文件的首字符
//	while (!feof(fp))
//	{
//		putchar(ch);    //把ch显示到屏幕上
//		ch = fgetc(fp);    //接收fp指向文件的下一个字符
//	}
//
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* fp = fopen("1.txt", "w+");
//	if (fp == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	char ch = getchar();
//	while (ch != '#')
//	{
//		ch = fputc(ch, fp);
//		ch = getchar();                                  //有bug
//	}
//	ch = fgetc(fp);
//	while (!feof(fp))
//	{
//		putchar(ch);
//		ch = fgetc(fp);
//	}
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

int main()
{
	FILE* fp;
	char arr[3][10], tmps[10];
	int i, j, k, n = 3;
	printf("输入字符串:>\n");
	for (i = 0; i < n; i++)
		gets(arr[i]);

	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(arr[k], arr[j]) > 0)     //k记录长度最小的字符串
				k = j;       
		}
		if (k != i)
		{
			strcpy(tmps, arr[i]);
			strcpy(arr[i], arr[k]);
			strcpy(arr[k], tmps);
		}
	}
	if ((fp = fopen("1.txt", "w")) == NULL)
	{
		printf("文件打开失败");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		fputs(arr[i], fp);
		fputs("\n", fp);
		printf("%s\n", arr[i]);
	}
	return 0;
}

