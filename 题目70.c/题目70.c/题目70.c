#include <stdio.h>

#define Max_size 20

int My_strlen(char* arr)
{
	int size = 0;    //�ַ������ȼ�����
	while (1)
	{
		if (*(arr + size) != '\0')    //����Ԫ�ؿ�ʼ�жϣ���Ϊ\0ʱsize����1��Ϊ\0ʱ����������size
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
	printf("�����ַ���:>");
	gets_s(arr,Max_size);    //gets��VS���ã�����Ϊgets_s
	int size = My_strlen(arr);
	printf("\n�ַ�������Ϊ%d\n", size);
	return 0;
}