#include <stdio.h>

int main ()
{
	int i;
	int a,b,c;
	c = 0;
	b = 0;
	a = 0;
	printf ("请输入学生的分数:>");
	scanf ("%d",&i);
	(i >= 90)? (a = i) : ((i >= 60) ? (b = i) : (c = i));
	printf ("a=%d\nb=%d\nc=%d\n",a,b,c);
	//main ();
	return 0;
}