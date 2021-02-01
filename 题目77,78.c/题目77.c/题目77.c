//#include <stdio.h>
//
//int main()
//{
//	//[]优先级高于*的优先级，所以str先与[]结合成为字符数组，后与*结合变成指向字符数组的指针
//	char* str[] = { "girl", "boy", "man", "woman", "yueduyuzhou" };
//	char** q;
//	//int size = sizeof(str) / sizeof(char);
//	for (int i = 0; i < 5; i++)
//	{
//		q = &str[i];	//两句效果相同
//		//q = str + i;    //q是一个二级指针，是指向指针的指针，此句把一级指针str指向的地址赋值给二级指针q，+i可以改变q指向第几个字符串元素
//		printf("%s\n\n", *q);
//	}
//
//	return 0;
//}