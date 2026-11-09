#include <stdio.h> 
int main ()
{
	int n;
	double sum=0;
	double a=2,b=1,t;
	for(n=1;n<=10;n++)
	{
		sum=sum+a/b;
		t=a;
		a=a+b;
		b=t;
	}
	printf("前10项之和=%.2f\n",sum);
	return 0;
}

