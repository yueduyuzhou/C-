#include <stdio.h>
#include <windows.h>		//��ӦSleep����
#include <stdlib.h>		//��Ӧsystem����

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

		Sleep(1000);		//ÿ��ӡһ��ͣ��1000����=1��
		system("cls");		//cls�����Ļ,systemִ��һ��ϵͳ����
		left++;
		right--;
	}
	printf ("%s\n",arr2);
	return 0;
}