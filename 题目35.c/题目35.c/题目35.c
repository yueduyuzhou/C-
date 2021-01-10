#include <stdio.h>
#include <windows.h>

int main()
{
	int color = 0;
	printf("设置文本颜色：0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色 10= 淡绿色 11=淡浅绿色 12=淡红色 13=淡紫色 14=淡黄色 15=亮白色\n");
	printf("请输入一个数字：");
	scanf_s("%d", &color);   //读取输入的数字，保存在color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | FOREGROUND_INTENSITY);   //根据输入数字显示颜色(前景色|加强)
	printf("YueDuYuZhou 2021/1/3\n");
	main();   //重复执行
	return 0;
}