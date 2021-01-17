#include <stdio.h>
#include <string.h>
#include <assert.h>



//1.暴力解算
//void Left_move(char* arr,int k)
//{
//	assert(arr != NULL);   //断言函数：判断arr是否有效
//	int i = 0;
//	int len = strlen(arr);   //计算字符串长度
//	for (i = 0; i < k; i++)   //旋转k个字符
//	{
//		char tmp = *arr;   //取出首元素
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);   //所有元素向前移动一位，空出最后一个位置
//		}
//		*(arr + len - 1) = tmp;   //在最后位置放入元素
//	}
//}


// 2.三步翻转法
//void Reverse(char* left, char* right)
//{
//	assert(left != NULL);   //断言函数：判断left是否有效
//	assert(right != NULL);   //断言函数：判断right是否有效
//	while (left < right)   //移动条件
//	{
//		char tmp = *left;   //
//		*left = *right;     //
//		*right = tmp;       //交换
//		left++;             //
//		right--;            //
//	}
//}
//
//
//void Left_move(char* arr, int k)
//{
//	assert(arr != NULL);   //断言函数：判断arr是否有效
//	int len = strlen(arr);   //计算字符串长度
//	assert(k <= len);   //旋转字母个数是在字符串长度范围内
//	Reverse(arr,arr + k - 1);   //左边移动
//	Reverse(arr + k,arr + len - 1);   //右边移动
//	Reverse(arr,arr + len - 1);   //整体移动
//}


//3.字符串追加法
int Is_Left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);    //计算字符串长度
	int len2 = strlen(str2);    //计算字符串长度
	if (len1 != len2)    //防止出现str2为str1子列时，判断为Yes
	{
		return 0;
	}

	strncat(str1, str1, len1);    //追加字符串
	char* ret = strstr(str1, str2);    //判断str2是否为str1的子列
	if (ret == NULL)    //是返回str2首元素地址，否返回NULL
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
	char arr1[20] = { "abcdef" };    //arr1后面要追加，所有长度设置得大一点
	char arr2[] = { "cdefab" };

	int ret = Is_Left_move(arr1, arr2);
	if (ret == 1)    //判断
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}


//判断旋转
//int Is_Left_move(char* s1, char* s2)
//{
//	int len = strlen(s1);   //计算字符串长度
//	int i = 0;
//	for (i = 0; i < len; i++)   //对比次数
//	{
//		Left_move(s1, 1);   //调用自定义旋转函数，每次旋转一个字符
//		int ret = strcmp(s1, s2);   //判断
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}


//int main()
//{   //待进一步完善
//	char arr1[] = { "abcdef" };
//	char arr2[] = { "cdefab" };
//	int ret = Is_Left_move(arr1, arr2);   //判断旋arr2是不是arr1旋转后得来
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
//{   //显示旋转效果，待进一步完善
//	char arr[] = "abcdef";
//	printf("旋转之前：%s\n", arr);
//	Left_move(arr, 2);
//	printf("旋转2个字符之后：%s\n", arr);
//	return 0;
//}