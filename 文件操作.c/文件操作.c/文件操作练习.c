#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main()
//{
//	//����һ��FILEָ��fp��ָ����'w'ֻд����ʽ�򿪵�1.txt�ļ�
//	FILE* fp = fopen("1.txt", "w");
//	//�ж��ļ������
//	if (fp == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	//���յ�һ���ַ�
//	char ch = getchar();
//	//ѭ����'#'����
//	while (ch != '#')
//	{
//		fputc(ch, fp);    //��ch�ַ�д��fpָ����ļ�
//		putchar(ch);      //��ch��ʾ����Ļ��
//		ch = getchar();   //������һ���ַ�
//
//	}
//
//	fclose(fp);    //�ر�fpָ����ļ�
//	fp = NULL;   
//	return 0;
//}

//int main()
//{
//	FILE* fp = fopen("1.txt", "r");
//	if (fp == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	char ch = fgetc(fp);    //����fpָ���ļ������ַ�
//	while (!feof(fp))
//	{
//		putchar(ch);    //��ch��ʾ����Ļ��
//		ch = fgetc(fp);    //����fpָ���ļ�����һ���ַ�
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
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	char ch = getchar();
//	while (ch != '#')
//	{
//		ch = fputc(ch, fp);
//		ch = getchar();                                  //��bug
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
	printf("�����ַ���:>\n");
	for (i = 0; i < n; i++)
		gets(arr[i]);

	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(arr[k], arr[j]) > 0)     //k��¼������С���ַ���
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
		printf("�ļ���ʧ��");
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

