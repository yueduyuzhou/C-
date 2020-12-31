#include <stdio.h>
#include <windows.h>		//对应Sleep（）
#include <stdlib.h>		//对应system（）

int main ()

{
	char arr1[]="welcome to bit !!!!!!";
	char arr2[]="#####################";
	int left=0;
	int right=strlen(arr1)-1;

	while(left<=right)
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		printf ("%s\n",arr2);

		Sleep(1000);		//每打印一次停留1000毫秒=1秒
		system("cls");		//cls清空屏幕,system执行一个系统命令
		left++;
		right--;
	}
	printf ("%s\n",arr2);
	return 0;
}