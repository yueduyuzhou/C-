//#include <stdio.h>
//
//int main()
//{
//	//[]���ȼ�����*�����ȼ�������str����[]��ϳ�Ϊ�ַ����飬����*��ϱ��ָ���ַ������ָ��
//	char* str[] = { "girl", "boy", "man", "woman", "yueduyuzhou" };
//	char** q;
//	//int size = sizeof(str) / sizeof(char);
//	for (int i = 0; i < 5; i++)
//	{
//		q = &str[i];	//����Ч����ͬ
//		//q = str + i;    //q��һ������ָ�룬��ָ��ָ���ָ�룬�˾��һ��ָ��strָ��ĵ�ַ��ֵ������ָ��q��+i���Ըı�qָ��ڼ����ַ���Ԫ��
//		printf("%s\n\n", *q);
//	}
//
//	return 0;
//}