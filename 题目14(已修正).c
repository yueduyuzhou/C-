#include <stdio.h>

int main ()
{
	int a,c,z,i;
	int arr[100];
	scanf ("%d",&z);
	printf ("%d=",z);
	a = 0;
	for (c = 2;z != 1;)	//�ж������Ƿ��������ҵ�
	{
		if (z%c == 0)  //�ж��ܷ�����
		{
			z = z/c;
			arr[a] = c;  //��������
			a++;  //������������
			c = 2;
			//for (d = 0;d < 100;d++)
			//{
				//arr[d] = c;
				//c = 2;
				//break;
			//}
		}
		else
		{
			c++;
		}
	}
	
	printf ("%d",arr[0]);
	for (i = 1;i < a;i++)
	{
		printf ("*%d",arr[i]);
	}
	printf ("\n");
	main ();  //һ�������м�����
	return 0;
}
