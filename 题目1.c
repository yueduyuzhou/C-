#include <stdio.h>

int main()
{
	int  a,s,d,k[100],n=0;
	for(a=1;a<=4;a++)
		for(s=1;s<=4;s++)
			for(d=1;d<=4;d++)
				if(a!=s&&s!=d&&a!=d)
				{
				k[n]=(a*100+s*10+d);
				n++;
				}
	printf("��1��4��ϵ���λ���У����ֲ��ظ�����%d��\n",n);
	printf("�ֱ���:");
	for(a=0;a<n;a++)
	{
		printf("%d",k[a]);
		printf("\n");
	}
	return 0;
	
}