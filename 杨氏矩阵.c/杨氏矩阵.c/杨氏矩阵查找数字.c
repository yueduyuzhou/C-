#include <stdio.h>

int FindNum(int arr[3][3], int k, int* px, int* py)    //用指针操作主函数的x，y
{
	int x = 0, y = *py - 1;
	while (x <= *px-1 && y >= 0)    //从矩阵右上角开始向左下角寻找
	{
		if (arr[x][y] > k)
		{
			y--;    //每次不符合干掉一列
		}
		else if (arr[x][y] < k)
		{
			x++;    //每次不符合干掉一行
		}
		else
		{
			*px = x;    //赋值主函数x
			*py = y;    //赋值主函数y
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };    //设置杨氏矩阵
	int k = 0, x = 3, y = 3;

	printf("输入一个数：");
	scanf("%d", &k);    //输入一个k
	int ret = FindNum(arr, k, &x, &y);    //自定义查找函数
	if (ret == 1)    //判断
	{
		printf("找到了\n");
		printf("下标是（%d,%d）。",x, y);
	}
	else
	{
		printf ("找不到\n");
	}

	return 0;
}