#include <stdio.h>

#define Max_size 20

int My_strlen(char* arr)
{
	int size = 0;    //字符串长度计数器
	while (1)
	{
		if (*(arr + size) != '\0')    //从首元素开始判断，不为\0时size自增1，为\0时跳出并返回size
		{
			size++;
		}
		else
		{
			break;
		}
	}
	return size;
}

int main()
{
	char arr[Max_size];
	printf("输入字符串:>");
	gets_s(arr,Max_size);    //gets被VS弃用，改用为gets_s
	int size = My_strlen(arr);
	printf("\n字符串长度为%d\n", size);
	return 0;
}