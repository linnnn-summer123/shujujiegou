#include <stdio.h> 
int main ()
{
	double c;
	double f; 
	printf("请输入一个摄氏温度");
	scanf("%lf",&c) ;
	f=9/5*c+32;
	printf("华氏温度=%2.f\n",f);
	return 0;

