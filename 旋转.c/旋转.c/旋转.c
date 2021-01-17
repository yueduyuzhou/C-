#include <stdio.h>
#include <string.h>
#include <assert.h>



//1.��������
//void Left_move(char* arr,int k)
//{
//	assert(arr != NULL);   //���Ժ������ж�arr�Ƿ���Ч
//	int i = 0;
//	int len = strlen(arr);   //�����ַ�������
//	for (i = 0; i < k; i++)   //��תk���ַ�
//	{
//		char tmp = *arr;   //ȡ����Ԫ��
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);   //����Ԫ����ǰ�ƶ�һλ���ճ����һ��λ��
//		}
//		*(arr + len - 1) = tmp;   //�����λ�÷���Ԫ��
//	}
//}


// 2.������ת��
//void Reverse(char* left, char* right)
//{
//	assert(left != NULL);   //���Ժ������ж�left�Ƿ���Ч
//	assert(right != NULL);   //���Ժ������ж�right�Ƿ���Ч
//	while (left < right)   //�ƶ�����
//	{
//		char tmp = *left;   //
//		*left = *right;     //
//		*right = tmp;       //����
//		left++;             //
//		right--;            //
//	}
//}
//
//
//void Left_move(char* arr, int k)
//{
//	assert(arr != NULL);   //���Ժ������ж�arr�Ƿ���Ч
//	int len = strlen(arr);   //�����ַ�������
//	assert(k <= len);   //��ת��ĸ���������ַ������ȷ�Χ��
//	Reverse(arr,arr + k - 1);   //����ƶ�
//	Reverse(arr + k,arr + len - 1);   //�ұ��ƶ�
//	Reverse(arr,arr + len - 1);   //�����ƶ�
//}


//3.�ַ���׷�ӷ�
int Is_Left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);    //�����ַ�������
	int len2 = strlen(str2);    //�����ַ�������
	if (len1 != len2)    //��ֹ����str2Ϊstr1����ʱ���ж�ΪYes
	{
		return 0;
	}

	strncat(str1, str1, len1);    //׷���ַ���
	char* ret = strstr(str1, str2);    //�ж�str2�Ƿ�Ϊstr1������
	if (ret == NULL)    //�Ƿ���str2��Ԫ�ص�ַ���񷵻�NULL
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int main()
{
	char arr1[20] = { "abcdef" };    //arr1����Ҫ׷�ӣ����г������õô�һ��
	char arr2[] = { "cdefab" };

	int ret = Is_Left_move(arr1, arr2);
	if (ret == 1)    //�ж�
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}


//�ж���ת
//int Is_Left_move(char* s1, char* s2)
//{
//	int len = strlen(s1);   //�����ַ�������
//	int i = 0;
//	for (i = 0; i < len; i++)   //�Աȴ���
//	{
//		Left_move(s1, 1);   //�����Զ�����ת������ÿ����תһ���ַ�
//		int ret = strcmp(s1, s2);   //�ж�
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}


//int main()
//{   //����һ������
//	char arr1[] = { "abcdef" };
//	char arr2[] = { "cdefab" };
//	int ret = Is_Left_move(arr1, arr2);   //�ж���arr2�ǲ���arr1��ת�����
//	if (ret == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}


//int main()   
//{   //��ʾ��תЧ��������һ������
//	char arr[] = "abcdef";
//	printf("��ת֮ǰ��%s\n", arr);
//	Left_move(arr, 2);
//	printf("��ת2���ַ�֮��%s\n", arr);
//	return 0;
//}