#include <stdio.h>

int main()
{
	int letter = 0, space = 0, num = 0, others = 0; //�����ַ�
	char temp;
	
	for (;(temp = getchar())!= 10;)
	{
		if (temp >= 65 && temp <= 90 || temp >= 97 && temp <= 122)  //ɸѡ����ĸ
			letter++;  //��¼��ĸ����
		else if (temp == 32)  //ɸѡ���ո�
			space++;  //��¼�ո����
		else if (temp >= 48 && temp <= 57)  //ɸѡ������
			num++;  //��¼���ָ���
		else  
			others++;  //��¼�����ַ�����
	}
	printf("�ַ�������%d����ĸ��%d���ո�%d�������Լ�%d�������ַ���\n", letter, space, num, others);
	//main();  //��Ҫ�ظ�ʹ���ǽ��ע��
	return 0;
}