#include <stdio.h>

int main()

{
	char arr[]="hello world";
	memset (arr,'*',5);
	printf ("%s\n",arr);
	return 0;

}