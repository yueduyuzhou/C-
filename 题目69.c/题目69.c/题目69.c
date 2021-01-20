#include <stdio.h>
#include <stdlib.h>

//试图用多层循环来写，未成功
//int* InitArr(int n)
//{
//	int arr[n - 1];
//	//for (int i = 0, int j = 1; i < n; i++, j++)
//	//{
//	//	arr[i] = j;
//	//	if (j == 3)
//	//	{
//	//		j = 0;
//	//	}
//	//}
//	for (int i = 1; i <= n; i++)
//	{
//		arr[i - 1] = i;
//	}
//	return arr;
//}

int main()
{
	int n = 0;
	int i = 0, j = 0;
	int num = 0;
	printf("输入人数:>");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));    //开辟n个int型的空间给arr
	for (j = 0; j < n; j++)
	{
		arr[j] = 0;
	}
	//int* arr = InitArr(n);

	j = 1;
	while (n - num != 1)    //判断是否还有不止一个元素，是继续，否跳出
	{
		for (i = 0; i < n; i++, j++)    //从数组头至尾依次遍历
		{
			//if (arr[i] % 3 == 0)
			//{
			//	arr[i] = 0;
			//	num++;
			//}
			while (arr[i] == 1)    //判断是否已被标记
			{
				if (i == n - 1 && n - num != 1) i = 0;    //如果判断的是最后一个元素且未被标记的元素还有不只一个，跳到第一个元素    
				else i++;    //否则i自增1
			}
			if (j == 3)   //每次循环到j=3时，标记当前元素位1，且num自增1，j变为0
			{
				arr[i] = 1;
				j = 0, num++;
			}
		}
	}
	for (j = 0; j < n; j++)    //查找剩下的唯一一个未被标记的元素下标
	{
		if (arr[j] == 0)
		{
			break;
		}
	}
	printf("留下来的是%d号\n\n", j + 1);    //号数是下标+1

	free(arr);    //释放arr所指向的已开辟空间
	arr = NULL;
	//重复执行
	//main();
	return 0;
}

