#include <stdio.h>

int main()

{
	int year,month,day,tolat;
	printf ("���������������գ�\n");
	scanf ("%d%d%d",&year,&month,&day);
	if (month==1)
		tolat=day;
	else if (month==2)
		tolat=31+day;
	else if (month==3)
		tolat=31+28+day;
	else if (month==4)
		tolat=31+28+31+day;
	else if (month==5)
		tolat=31+28+31+30+day;
	else if (month==6)
		tolat=31+28+31+30+31+day;
	else if (month==7)
		tolat=31+28+31+30+31+30+day;
	else if (month==8)
		tolat=31+28+31+30+31+30+31+day;
	else if (month==9)
		tolat=31+28+31+30+31+30+31+30+day;
	else if (month==10)
		tolat=31+28+31+30+31+30+31+30+31+day;
	else if (month==11)
		tolat=31+28+31+30+31+30+31+30+31+30+day;
	else if (month==12)
		tolat=31+28+31+30+31+30+31+30+31+30+31+day;
	if ((year%4==0&&year%100!=0)||(year%400==0))
		if (month>2)
			++tolat;

	printf("%d��%d��%d����%d��ĵ�%d��\n",year,month,day,year,tolat);

	return 0;
	
}
